/**
 * \file validationFormat.h
 * \brief Prototype de la librairy validationFormat
 * \author Marc-Anthony Girard
 * \date 29 septembere 2021
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

/**
 * \class validationFormat
 * \brief Bibliothèque validationFormat permettant de vérifier si des noms sont valides, des codes ISBN et des codes ISSN.
 */

bool validerFormatNom (const std::string& p_nom);
bool validerCodeIssn (const std::string& p_issn);
bool isStringDigit (const std::string& aValider);
bool validerCodeIsbn (const std::string& p_isbn);
bool isEditorValid (const std::string& aValider);
bool isDomaineValid (const std::string& aValider);

#endif /* VALIDATIONFORMAT_H_ */

