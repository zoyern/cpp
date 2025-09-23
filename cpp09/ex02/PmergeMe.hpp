/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>

/*
    FORD-JOHNSON MERGE-INSERTION SORT
    
    Algorithme de tri optimal en nombre de comparaisons développé par Ford & Johnson (1959).
    Minimise théoriquement le nombre de comparaisons nécessaires pour trier n éléments.
    
    Principe :
    1. Grouper les éléments par paires et déterminer gagnant/perdant (1 comparaison/paire)
    2. Trier récursivement les gagnants 
    3. Construire la "main chain" : gagnants triés + premier perdant bien placé
    4. Insérer les autres perdants selon la séquence de Jacobsthal (ordre optimal)
    5. Insérer l'élément impair restant (straggler) s'il existe
    
    Complexité : O(n log n) mais avec le nombre minimal de comparaisons théoriques
*/

class PmergeMe {
private:
    PmergeMe(); PmergeMe(const PmergeMe&); PmergeMe& operator=(const PmergeMe&); ~PmergeMe();

	static size_t nextJacobsthal(size_t seq[2], size_t limit) { return seq[0] = seq[1], seq[1] = seq[1] + 2 * seq[0], seq[1] <= limit ? seq[1] : limit; }

    template<template<typename, typename> class Contener, typename T>
    static Contener<T, std::allocator<T> > parse(int argc, char** argv) {
        Contener<T, std::allocator<T> > cont;
        for (int i = 0; i < argc; ++i) {
            std::stringstream ss(argv[i]); T val;
            if (!(ss >> val) || !ss.eof() || ss.fail() || val < T(0) || val > std::numeric_limits<T>::max()) throw std::runtime_error("Error");
            cont.push_back(val);
        }
        return (cont);
    }

	/*
        ÉTAPE 1 : FORMATION DES PAIRES ET DÉTERMINATION GAGNANT/PERDANT
        
        Groupe les éléments par paires adjacentes.
        Pour chaque paire, détermine le gagnant (plus grand) et le perdant (plus petit).
        1 seule comparaison par paire.
        
        @param c : container d'entrée (modifié pour optimisation mémoire)
        @param p : container de sortie contenant les paires {gagnant, perdant}
    */

    template<template<typename, typename> class Contener, typename T>
    static void fjjpairs(Contener<T, std::allocator<T> >& cont, Contener<std::pair<T,T>, std::allocator<std::pair<T,T> > >& pairs) {
        pairs.clear();
        for (size_t i = 0; i + 1 < cont.size(); i += 2)
            pairs.push_back(cont[i] > cont[i+1] ? std::make_pair(cont[i], cont[i+1]) : std::make_pair(cont[i+1], cont[i]));
    }

	/*
		ÉTAPE 2 : TRI RÉCURSIF DES GAGNANTS
		
		Extrait tous les gagnants des paires et les trie récursivement 
		en utilisant le même algorithme Ford-Johnson.
		
		Cas de base : ≤ 1 gagnant (déjà trié)
		Cas récursif : appel à fjj() sur les gagnants
		
		@param pairs : paires {gagnant, perdant}
		@return : gagnants triés par ordre croissant
	*/

    template<template<typename, typename> class Contener, typename T>
    static Contener<T, std::allocator<T> > fjjwinners(Contener<std::pair<T,T>, std::allocator<std::pair<T,T> > >& pairs) {
        Contener<T, std::allocator<T> > winners;
        if (pairs.size() <= 1) { if (!pairs.empty()) winners.push_back(pairs[0].first); return winners; }
        for (size_t i = 0; i < pairs.size(); ++i) winners.push_back(pairs[i].first);
        return fjj(winners);
    }

	/*
        ÉTAPE 3 : CONSTRUCTION DE LA MAIN CHAIN
        
        La "main chain" est la séquence de base pour les insertions suivantes.
        Elle contient :
        1. Tous les gagnants triés (base stable)
        2. Le premier perdant inséré à sa position optimale
        
        IMPORTANT : Le premier perdant n'est PAS forcément placé au début !
        Il est inséré à sa position triée grâce à lower_bound().
        
        @param cont : container de sortie (main chain)
        @param winners : gagnants triés 
        @param pairs : paires originales pour récupérer p[0].second (premier perdant)
    */

    template<template<typename, typename> class Contener, typename T>
    static void fjjchain(Contener<T, std::allocator<T> >& cont, Contener<T, std::allocator<T> > winners, const Contener<std::pair<T,T>, std::allocator<std::pair<T,T> > >& pairs) {
        cont = winners;
        if (!pairs.empty()) cont.insert(std::lower_bound(cont.begin(), cont.end(), pairs[0].second), pairs[0].second);
    }

    /*
        ÉTAPE 4 : INSERTION DES PERDANTS SELON JACOBSTHAL
        
        CŒUR DE L'ALGORITHME FORD-JOHNSON
        
        Les perdants restants (indices 1,2,3...) sont insérés selon la séquence 
        de Jacobsthal pour minimiser le nombre total de comparaisons.
        
        Ordre d'insertion : groupes Jacobsthal en ORDRE DÉCROISSANT
        Exemple si Jac = [1,1,3,5] et 6 perdants :
        - Groupe 1 : perdant[0] (déjà inséré dans main chain)
        - Groupe 2 : perdants[2,1] dans cet ordre (décroissant !)  
        - Groupe 3 : perdants[4,3] dans cet ordre
        - etc.
        
        @param cont : main chain (sera modifiée par insertions successives)
        @param pairs : paires contenant les perdants à insérer
    */

    template<template<typename, typename> class Contener, typename T>
    static void fjjlosers(Contener<T, std::allocator<T> >& cont, const Contener<std::pair<T,T>, std::allocator<std::pair<T,T> > >& pairs) {
        if (pairs.size() <= 1) return;
        size_t jac[2] = {1,1}, curr = 1;
        while (curr < pairs.size()) {
            size_t end = nextJacobsthal(jac, pairs.size());
            for (size_t i = end; i > curr; --i)
                cont.insert(std::lower_bound(cont.begin(), cont.end(), pairs[i-1].second), pairs[i-1].second);
            curr = end;
        }
    }
 
	/*
        ALGORITHME PRINCIPAL FORD-JOHNSON
        
        Orchestre les 5 étapes de l'algorithme :
        1. Formation des paires
        2. Tri des gagnants (récursif)  
        3. Construction main chain
        4. Insertion des perdants (Jacobsthal)
        5. Insertion du straggler
        
        @param cont : container à trier (copié pour éviter modification de l'original)
        @return : container trié
    */
    template<template<typename, typename> class Contener, typename T>
    static Contener<T, std::allocator<T> > fjj(Contener<T, std::allocator<T> > cont) {
        Contener<std::pair<T,T>, std::allocator<std::pair<T,T> > > pairs;
        bool odd = cont.size() % 2;
		T rem = odd ? cont.back() : T();
        fjjpairs(cont, pairs);
		fjjchain(cont, fjjwinners(pairs), pairs);
		fjjlosers(cont, pairs);
        if (odd) cont.insert(std::lower_bound(cont.begin(), cont.end(), rem), rem);
        return (cont);
    }

public:
    /*
        INTERFACES PUBLIQUES
        
        Templates supportant différents types numériques (int, float, double...)
        et différents containers (std::vector, std::deque)
        
        @param argc : nombre d'arguments
        @param argv : arguments en chaînes de caractères
        @return : container trié du type demandé
    */
    template<typename T> static std::vector<T> sortVector(int argc, char** argv) { return (fjj(parse<std::vector, T>(argc, argv))); }
    template<typename T> static std::deque<T> sortDeque(int argc, char** argv) { return (fjj(parse<std::deque, T>(argc, argv))); }
};

