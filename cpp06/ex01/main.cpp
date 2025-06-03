/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // 1. Création d'une instance de Data
    Data original;
    original.id = 42;
    original.name = "Example Data";
    original.active = true;

    std::cout << "Original Data:\n";
    std::cout << "  id: " << original.id << "\n";
    std::cout << "  name: " << original.name << "\n";
    std::cout << "  active: " << (original.active ? "true" : "false") << "\n";

    // 2. Sérialisation (on "transforme" le pointeur en entier)
    unsigned long raw = Serializer::serialize(&original);
    std::cout << "\n[Serialized Pointer]: " << raw << "\n";

    // 3. Désérialisation (on récupère un pointeur à partir de l'entier)
    Data* recovered = Serializer::deserialize(raw);

    // 4. Vérification : les données sont-elles identiques ?
    std::cout << "\nRecovered Data:\n";
    std::cout << "  id: " << recovered->id << "\n";
    std::cout << "  name: " << recovered->name << "\n";
    std::cout << "  active: " << (recovered->active ? "true" : "false") << "\n";

    // 5. Adresse mémoire pour confirmer qu'on a bien le même objet
    std::cout << "\n[Original address]:  " << &original << "\n";
    std::cout << "[Recovered address]: " << recovered << "\n";

    // 6. Résultat logique
    if (recovered == &original)
        std::cout << "\n✅ La désérialisation a bien récupéré le même objet !\n";
    else
        std::cout << "\n❌ Erreur : pointeur différent !\n";

    return 0;
}