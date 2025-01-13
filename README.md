"# PowShift" 

A Unique Binary Encryption with `Math.Pow` Algorithm

Its shifting current byte value by current index * 5 until half index, and other part of file is reversed

## Usage
- Clone the repository
    ```bash
    git clone https://github.com/Putra3340/PowShift.git
    ```
- Build it with
    ```bash
    make
    ```
- Encrypt
    ```bash
    ./bin/encryption -i example.dat -o example.enc --encrypt
    ```
- Decrypt
    ```bash
    ./bin/encryption -i example.enc -o example.dec --decrypt
    ```

Currently can shift Pow by 5 but the half reversed is not Done yet.