# Libft

![42 School Badge](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)
![C Badge](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)

**Libft** is a custom C library containing reimplementations of standard C library functions, created as part of the 42 School curriculum. This project serves as the foundation for all subsequent 42 projects, providing essential functions that will be used throughout the program.

## 📋 Table of Contents

- [About](#about)
- [Functions](#functions)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Contributing](#contributing)
- [Author](#author)

## 🎯 About

The libft project challenges students to understand how the standard C library functions work by implementing them from scratch. This exercise deepens understanding of:

- **Memory management** and pointer manipulation
- **String handling** and character operations  
- **Linked list** data structures
- **Standard algorithms** and their implementation
- **Makefile** creation and project organization

The library is designed to be reusable across all future 42 School projects, making it a critical foundation for success in the curriculum.

## 📚 Functions

### Part 1 - Libc Functions
Recreation of standard C library functions with the `ft_` prefix:

#### Character Functions
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is numeric  
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

#### String Functions
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (from end)
- `ft_strncmp` - Compare strings up to n characters
- `ft_strnstr` - Locate substring in string
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate strings with size limit

#### Memory Functions
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas

#### Conversion Functions
- `ft_atoi` - Convert string to integer
- `ft_calloc` - Allocate and zero memory
- `ft_strdup` - Duplicate string

### Part 2 - Additional Functions
Original functions not in the standard library:

- `ft_substr` - Extract substring
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from string ends
- `ft_split` - Split string by delimiter
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character (with index)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string + newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

### Bonus Part - Linked Lists
Functions for manipulating linked lists:

- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element to front of list
- `ft_lstsize` - Count elements in list
- `ft_lstlast` - Get last element of list
- `ft_lstadd_back` - Add element to back of list
- `ft_lstdelone` - Delete single element
- `ft_lstclear` - Delete and free entire list
- `ft_lstiter` - Apply function to each element
- `ft_lstmap` - Apply function and create new list

## 🚀 Installation

1. **Clone the repository:**
```bash
git clone https://github.com/herom-s/libft.git
cd libft
```

2. **Compile the library:**
```bash
make
```

3. **For bonus functions:**
```bash
make bonus
```

4. **Clean object files:**
```bash
make clean
```

5. **Remove all generated files:**
```bash
make fclean
```

6. **Recompile everything:**
```bash
make re
```

## 💻 Usage

### Basic Usage

Include the header in your C files:
```c
#include "libft.h"
```

Compile your program with the library:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

### Example Usage

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = "Hello, 42!";
    char *upper_str;
    char **split_result;
    
    // String manipulation
    printf("Original: %s\n", str);
    printf("Length: %zu\n", ft_strlen(str));
    
    // Convert to uppercase using ft_strmapi
    upper_str = ft_strmapi(str, (char (*)(unsigned int, char))ft_toupper);
    printf("Uppercase: %s\n", upper_str);
    
    // Split string
    split_result = ft_split(str, ' ');
    printf("First word: %s\n", split_result[0]);
    
    // Clean up
    free(upper_str);
    // Remember to free split_result array and its elements
    
    return (0);
}
```

## 🧪 Testing

### Recommended Testing Tools

- **[libft-unit-test](https://github.com/alelievr/libft-unit-test)** - Comprehensive unit tests
- **[libftTester](https://github.com/Tripouille/libftTester)** - Popular testing framework
- **[francinette](https://github.com/xicodomingues/francinette)** - 42 project tester
- **[libftDangerZone](https://github.com/herom-s/libftDangerZone)** - My own libft tester

### Running Tests

```bash
# Example with libftDangerZone
git clone https://github.com/herom-s/libftDangerZone.git
cd libftDangerZone
make # Compile project and its dependencies
make test # Test all the fuctions
```

## 📁 Project Structure

```
libft/
├── Makefile          # Build configuration
├── libft.h           # Header file with function prototypes
├── ft_*.c            # Source files for each function
├── libft.a           # Compiled static library (after make)
└── README.md         # This file
```

## 🔧 Compilation

The project includes a comprehensive Makefile with the following rules:

- **`make`** or **`make all`** - Compile the library
- **`make bonus`** - Include bonus functions
- **`make clean`** - Remove object files
- **`make fclean`** - Remove object files and library
- **`make re`** - Recompile everything

**Compilation Flags:**
- `-Wall -Wextra -Werror` - Enable all warnings and treat them as errors

## 📋 Requirements

- **Language:** C (C99 standard)
- **Compiler:** GCC or Clang
- **OS:** Unix-like systems (Linux, macOS)
- **Memory:** All heap-allocated memory must be properly freed
- **Norm:** Code must follow 42 School's coding standard (Norminette)

## 🤝 Contributing

This is a 42 School project and should be completed individually. However, after evaluation, contributions for improvements are welcome:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add some improvement'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

## 👨‍💻 Author

**herom-s** - *42 School Student*

- GitHub: [@herom-s](https://github.com/herom-s)
- 42 Intranet: `hermarti`

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎓 42 School

This project is part of the 42 School curriculum. 42 is a future-proof computer science training program that teaches students to code through peer-to-peer learning and project-based education.

---

**Note:** If you are a current 42 student, I encourage you to understand and write your own implementation rather than copying code. The learning process and problem-solving experience are more valuable than the final result.

*"The only way to learn a new programming language is by writing programs in it."* - Dennis Ritchie
