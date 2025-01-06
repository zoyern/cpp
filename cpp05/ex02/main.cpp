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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <dirent.h>  // Pour opendir, readdir, closedir
#include <sys/stat.h> // Pour stat

bool containsSubdirectories(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (dir == NULL)
        return false;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string name = entry->d_name;

        // Ignorer les entrées spéciales "." et ".." ainsi que les fichiers cachés
        if (name == "." || name == ".." || name[0] == '.')
            continue;

        std::string fullPath = path + "/" + name;

        struct stat info;
        if (stat(fullPath.c_str(), &info) == 0 && S_ISDIR(info.st_mode)) {
            closedir(dir);
            return true; // Contient au moins un sous-dossier
        }
    }

    closedir(dir);
    return false; // Pas de sous-dossiers trouvés
}

void printTree(const std::string& path, int depth = 0) {
    DIR* dir = opendir(path.c_str()); // Ouvrir le répertoire
    if (dir == NULL) {
        std::cerr << "Erreur : Impossible d'ouvrir le dossier : " << path << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string name = entry->d_name;

        // Ignorer les entrées spéciales "." et ".." ainsi que les fichiers cachés
        if (name == "." || name == ".." || name[0] == '.')
            continue;

        std::string fullPath = path + "/" + name;

        // Vérifier si c'est un dossier
        struct stat info;
        if (stat(fullPath.c_str(), &info) == 0 && S_ISDIR(info.st_mode)) {
            // Affichage de l'arborescence
            for (int i = 0; i < depth; ++i) {
                std::cout << "    ";
            }
            std::cout << "|-- " << name << std::endl;

            // Si le dossier contient des sous-dossiers, continuer la récursion
            printTree(fullPath, depth + 1);

        } else if (!containsSubdirectories(path)) {
            // Si le dossier parent est une "feuille", afficher les fichiers
            for (int i = 0; i < depth; ++i) {
                std::cout << "    ";
            }
            std::cout << "|-- [File] " << name << std::endl;
        }
    }

    closedir(dir); // Fermer le dossier
}

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new AForm();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new AForm("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		// Assistant signs the AForm
		try
		{
			// c->beSigned(*a);
			a->signForm(*c);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the AForm
		std::cout << c;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << c;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		AForm *a = NULL;

		// sign-grade too high
		try
		{
			a = new AForm(160, 145);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new AForm(145, 160);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new AForm(-15, 145);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new AForm(145, -15);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " << e.what() << "\033[0m" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}

	std::string folderPath = "../../"; // Chemin de départ
    std::cout << "Arborescence des dossiers dans : " << folderPath << std::endl;
    printTree(folderPath);
	return (0);
}