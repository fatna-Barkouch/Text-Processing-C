# Text Processing Project

This project is a simple text processing program written in C. It was developed as part of a university module called "Compilation" during the second year of studies in 2016.

The program reads text files, extracts lines and words, and performs various analyses on the words present in the file. It categorizes the words based on certain criteria, such as keywords, operators, special characters, identifiers, and real numbers.

## Features

- Extract lines from a given text file and store them as separate strings in memory.
- Extract words from each line and store them as separate strings in memory.
- Identify and categorize words as:
  - Keywords: Words found in a list of keywords provided in `motcle.txt`.
  - Operators: Words found in a list of operators provided in `operateur.txt`.
  - Special characters: Words found in a list of special characters provided in `caracterespecial.txt`.
  - Identifiers: Words that follow certain rules (e.g., start with a letter or underscore).
  - Real numbers: Words that represent valid real numbers.
- Generate an output file (`generateFile.txt`) that contains the analyzed properties of each word in the input file (`test.txt`).

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC) to compile the C source code.

### How to Use

1. Clone the repository to your local machine.
2. Place the text file you want to process (`test.txt`) in the same directory as the source code.
3. Make sure to have the `motcle.txt`, `operateur.txt`, and `caracterespecial.txt` files in the same directory with lists of keywords, operators, and special characters respectively.
4. Compile the program using your preferred C compiler:
5.s The program will process `test.txt`, and the results will be saved in `generateFile.txt`.

## Contributing

Contributions are welcome! If you have suggestions for improvements or want to report any issues, please feel free to create a pull request or submit an issue.

## License

This project is licensed under the [MIT License](LICENSE).

