#ifndef CUSTOM_EXCEPTIONS
#define CUSTOM_EXCEPTIONS

#include <stdexcept>
#include <string>

/**
 * @brief Classe para tratamento de exceções de argumento inválido.
 */
class InvalidArgumentException : public std::invalid_argument {
public:
    InvalidArgumentException(const std::string& description);
};

/**
 * @brief Classe para tratamento de exceções de lógica.
 */
class NotFoundException : public std::logic_error {
public:
    NotFoundException(const std::string& description);
};

/**
 * @brief Classe para tratamento de exceções de tipo inválido.
 */
class InvalidTypeException : public std::invalid_argument {
public:
    InvalidTypeException(const std::string& description);
};

#endif // CUSTOM_EXCEPTIONS
