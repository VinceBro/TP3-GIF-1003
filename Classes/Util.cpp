/**
 * \file Util.cpp
 * \brief Fonctions du namespace util
 * \author Vincent Breault
 * \date
 */
#include "Util.h"
using namespace std;

/**
 * \fn validerFormatNom
 * \brief Vérifie si le nom est valide
 * \param p_nom
 */
bool util::validerFormatNom(const string &p_nom){
    bool valide = true;

    string str = p_nom;
    if (str.empty()) valide = false;
    if (int(str[0]) == 32) valide = false;
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {

        if (not((97 <= int(*it) and int(*it) <= 122) or (65 <= int(*it) and int(*it) <=90)or (int(*it) == 32))){
            valide = false;
                }
    }
    return valide;
}
/**
 * \fn validerCodeIssn
 * \brief Vérifie si le code ISSN est valide
 * \param p_issn
 */
bool util::validerCodeIssn(const string &p_issn){
    bool valide = true;
    int total = 0;
    string str = p_issn;

    if (str.length() != 14)
        valide = false;

    if (int(str[0]) != 73 or int(str[1]) != 83 or int(str[2]) != 83  or int(str[3]) != 78 or int(str[4]) != 32){
        valide = false;
    }
    for (int i = 5; i<=13; i++){
        if (i == 9 and int(str[i]) != 45)
            valide = false;
        if (i != 9  and not (48 <= int(str[i]) and int(str[i]) <= 57))
            valide = false;
    }
    total = ((int(str[5])-48)* 8) + ((int(str[6])-48)* 7) + ((int(str[7])-48)* 6) + ((int(str[8])-48)* 5) + ((int(str[10])-48)* 4) + ((int(str[11])-48)* 3) + ((int(str[12])-48)* 2);
    if (11 - total % 11 != (int(str[13]) - 48)){
        valide = false;
    }

    return valide;
}
/**
 * \fn validerCodeIsbn
 * \brief Vérifie si le code ISBN est valide
 * \param p_isbn
 */
bool util::validerCodeIsbn(const string &p_isbn){
    int j = 5;
    int somme = 0;
    bool valide = true;
    string str = p_isbn;
    int len = str.length();


    //regarde si les 5 premiers caractères sont ISBN{space}
    if (int(str[0]) != 73 or int(str[1]) != 83 or int(str[2]) != 66  or int(str[3]) != 78 or int(str[4]) != 32){
        valide = false;
    }
    //si ISBN-10
    if (len == 18){
        //de 5 à 17 sont les index d'où se situe les nombres et les tirets dans le ISBN 10
        for (int i = 5; i <=17 ; i++){
            //si i n'est pas un tiret alors on regarde si c'est un nombre
            if (int(str[i] != 45 and str[i] != 88)  and not (48 <= int(str[i]) and int(str[i]) <= 57))
                    valide = false;}
        for (int i = 10; i > 0; i--){
            if (int(str[j]) == 45) j++;
            if (int(str[j]) == 88) {
                somme += 10*i;
            }
            else somme += i * (int(str[j])-48);
            j++;
        }
        if (somme % 11 != 0) valide = false;

    } else if (len == 22){

        for (int i = 5; i <=21 ; i++){
            //si i n'est pas un tiret alors on regarde si c'est un nombre
            if (int(str[i] != 45)  and not (48 <= int(str[i]) and int(str[i]) <= 57))
                    valide = false;}
        for (int i = 0; i <= 12; i++){
            if (int(str[j]) == 45) j++;
            if (i % 2 == 0) somme+= (int(str[j]) - 48);
            else if (i % 2 != 0) somme += 3* (int(str[j]) - 48);
            j++;
        } if (somme % 10 != 0) valide = false;
    } else valide = false;
    return valide;
}
