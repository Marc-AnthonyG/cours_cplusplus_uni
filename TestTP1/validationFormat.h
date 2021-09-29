/*
 * File:   validationFormat.h
 * Author: Marc-Anthony Girard
 *
 * Created on 20 septembre 2021, 20:52
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_


#include <string>

bool validerFormatNom (const std::string& p_nom);
bool validerCodeIssn (const std::string& p_issn);
bool isStringDigit (const std::string& aValider);
bool checkLastDigit (int somme, std::string lastDigit);
bool validerCodeIsbn (const std::string& p_isbn);

#endif /* VALIDATIONFORMAT_H_ */

