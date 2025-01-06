#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>

// ---------------------------------------------------------------------
// TABLEAUX GLOBAUX
// ---------------------------------------------------------------------

static char* g_dirs[10000];
static int   g_dirsCount = 0;

static char* g_files[10000];
static int   g_filesCount = 0;

// ---------------------------------------------------------------------
// 1) parseDirectory : lit récursivement, ignore fichiers/dossiers cachés
// ---------------------------------------------------------------------
void parseDirectory(const char* path)
{
    DIR* dir = opendir(path);
    if (!dir) {
        std::cerr << "Impossible d'ouvrir : " << path << std::endl;
        return;
    }

    // On stocke path dans g_dirs
    if (g_dirsCount < 10000) {
        int len = std::strlen(path);
        char* copyPath = new char[len + 1];
        for (int i=0; i<len; i++){
            copyPath[i] = path[i];
        }
        copyPath[len] = '\0';
        g_dirs[g_dirsCount++] = copyPath;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        const char* name = entry->d_name;

        // Ignorer . et ..
        if (std::strcmp(name, ".")==0 || std::strcmp(name, "..")==0)
            continue;
        // Ignorer cachés
        if (name[0] == '.')
            continue;

        // Construire fullPath
        char fullPath[1024];
        std::strcpy(fullPath, path);
        std::strcat(fullPath, "/");
        std::strcat(fullPath, name);

        // stat
        struct stat st;
        if (stat(fullPath, &st)==0 && S_ISDIR(st.st_mode)) {
            // Dossier => récursif
            parseDirectory(fullPath);
        } else {
            // Fichier
            if (g_filesCount<10000) {
                int flen = std::strlen(fullPath);
                char* copyFile = new char[flen+1];
                for (int i=0; i<flen; i++){
                    copyFile[i] = fullPath[i];
                }
                copyFile[flen]='\0';
                g_files[g_filesCount++] = copyFile;
            }
        }
    }
    closedir(dir);
}

// ---------------------------------------------------------------------
// 2) countDirectSubDirs : renvoie nb de sous-dossiers *directs*
//    (pas sous-sous-dossiers), c.-à-d. "dirPath/quelquechose" 
//    sans '/' supplémentaire
// ---------------------------------------------------------------------
int countDirectSubDirs(const char* dirPath)
{
    int dirLen = std::strlen(dirPath);
    int count = 0;
    for (int i=0; i<g_dirsCount; i++){
        const char* candidate = g_dirs[i];
        if (std::strncmp(candidate, dirPath, dirLen)==0) {
            if (candidate[dirLen] == '/') {
                // On regarde s'il y a un autre '/'
                const char* afterSlash = candidate + (dirLen+1);
                const char* found = std::strchr(afterSlash, '/');
                if (!found) {
                    // Ni '.' => c'est un sous-dossier direct
                    if (std::strcmp(candidate, dirPath)!=0) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

// ---------------------------------------------------------------------
// 3) Dessin du tronc selon subCount, version “automatique”
// ---------------------------------------------------------------------
void drawTrunk(int subCount)
{
    if (subCount<=0) return;

    // Selon la logique demandée
    if (subCount==1) {
        // ||
        std::cout << "||" << std::endl;
    }
    else if (subCount==2) {
        // \//
        // ||||
        std::cout << "\\//" << std::endl;
        std::cout << "||||" << std::endl;
    }
    else if (subCount==3) {
        // \||//
        // ||||||
        std::cout << "\\||//" << std::endl;
        std::cout << "||||||" << std::endl;
    }
    else if (subCount==4) {
        //        \//
        //      \||||//
        //       ||||||||
        std::cout << "       \\//" << std::endl;
        std::cout << "     \\||||//" << std::endl;
        std::cout << "      ||||||||" << std::endl;
    }
    else if (subCount==5) {
        //    \||//
        //  \||||||//
        //   ||||||||||
        std::cout << "    \\||//" << std::endl;
        std::cout << "  \\||||||//" << std::endl;
        std::cout << "   ||||||||||" << std::endl;
    }
    else if (subCount==6) {
        //  \//
        // \|||||//
        // \||||||||||//
        //  ||||||||||||
        std::cout << "  \\//" << std::endl;
        std::cout << " \\|||||//" << std::endl;
        std::cout << "\\||||||||||//" << std::endl;
        std::cout << " ||||||||||||" << std::endl;
    }
    // etc. si subCount>6
}

// ---------------------------------------------------------------------
// 4) printTrunkRecursive : 
//    - Affiche le nom du dossier
//    - Calcule subCount => affiche le tronc
//    - Appelle récursivement sur chaque sous-dossier direct
//    => plus de subcount dans le main, c'est automatique
// ---------------------------------------------------------------------
void printTrunkRecursive(const char* dirPath, int level)
{
    // Indentation si vous voulez (optionnel)
    for (int i=0; i<level; i++){
        std::cout << "   "; // 3 espaces
    }
    // Afficher le dossier
    std::cout << dirPath << std::endl;

    // Calcul subCount
    int subCount = countDirectSubDirs(dirPath);

    // Dessin du tronc
    // On l'affiche *sous* ce nom, + indentation si vous voulez
    for (int i=0; i<level; i++){
        std::cout << "   ";
    }
    drawTrunk(subCount);

    // Récupérer la liste des sous-dossiers directs
    // On va les stocker dans un tableau local
    const char* subArray[100];
    int subArrCount=0;

    // Parcourt g_dirs pour trouver les sous-dossiers directs
    int dirLen = std::strlen(dirPath);
    for (int i=0; i<g_dirsCount; i++){
        const char* candidate = g_dirs[i];
        if (std::strncmp(candidate, dirPath, dirLen)==0){
            if (candidate[dirLen]=='/'){
                const char* afterSlash = candidate + (dirLen+1);
                const char* found = std::strchr(afterSlash, '/');
                if (!found){
                    if (std::strcmp(candidate, dirPath)!=0){
                        // c'est un sous-dossier direct
                        if (subArrCount<100){
                            subArray[subArrCount++]=candidate;
                        }
                    }
                }
            }
        }
    }

    // Pour chaque sous-dossier direct => appel récursif
    // => level+1
    for (int i=0; i<subArrCount; i++){
        printTrunkRecursive(subArray[i], level+1);
    }
}

// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------

int main(int argc, char** argv)
{
    if (argc<2){
        std::cerr << "Usage: " << argv[0] << " <directory_path>\n";
        return 1;
    }

    const char* startPath = argv[1];

    parseDirectory(startPath);

    // 1) Affichage initial
    std::cout << "==== Dossiers (non cachés) : " << g_dirsCount << " ====\n";
    for (int i=0; i<g_dirsCount; i++){
        std::cout << g_dirs[i] << "\n";
    }
    std::cout << "\n==== Fichiers (non cachés) : " << g_filesCount << " ====\n";
    for (int i=0; i<g_filesCount; i++){
        std::cout << g_files[i] << "\n";
    }

    // 2) Affichage récursif "tronc" pour *chaque* dossier, 
    //    en partant du dossier racine = startPath
    // => on suppose startPath a bien été stocké dans g_dirs[0].
    //    Mais s'il n'est pas en g_dirs[0], on le cherche.
    //    Pour être sûr, on peut faire :
    int idxRoot=-1;
    for (int i=0; i<g_dirsCount; i++){
        if (std::strcmp(g_dirs[i], startPath)==0){
            idxRoot=i;
            break;
        }
    }
    if (idxRoot<0){
        std::cerr << "startPath non trouvé dans g_dirs!\n";
    } else {
        std::cout << "\n==== Arbre récursif ====\n\n";
        printTrunkRecursive(g_dirs[idxRoot], 0);
    }

    // Libération
    for (int i=0; i<g_dirsCount; i++){
        delete[] g_dirs[i];
        g_dirs[i]=0;
    }
    for (int i=0; i<g_filesCount; i++){
        delete[] g_files[i];
        g_files[i]=0;
    }

    return 0;
}
