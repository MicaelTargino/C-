#include "custom_exceptions.h"

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
InvalidArgumentException::InvalidArgumentException(const std::string& description)
    : std::invalid_argument(description) {}

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
NotFoundException::NotFoundException(const std::string& description)
    : std::logic_error(description) {}

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
InvalidTypeException::InvalidTypeException(const std::string& description)
    : std::invalid_argument(description) {}
