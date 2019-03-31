# Secure Hash Algorithm 256 (SHA-256)

## Program Definition
This is a program for **Theory of Algorithms** module of 4th year of **Software Development**. This repository contains code which is able to run SHA-256 on passed in files.

## Problem Statement
You must write a program in the C programming languaage that calculates the SHA-256 checksum of an input. The algorithm is specified in the Secure Hash Standard document supplied by the (United States) National Institute of Standards and Technology. The only pre-requisite is that your program performs the algorithm - you are free to decide what input the algorithm should be performed on. I suggest you allow the user to input some free text or a filename via the command line.

## SHA-256
* **SHA256** stands for Secure Hash Algorithm 256-bit and it’s used for cryptographic security.
* **Cryptographic hash algorithms** produce irreversible and unique hashes. The larger the number of possible hashes, the smaller the chance that two values will create the same hash. 
* Is defined as one of the most secure ways to protect digital information. SHA 256 is a math process that generates a 256 bit (64 character long) random sequence of letters and numbers (hash) out of any input.
* A **hash** is as a mathematical computer process that takes information and turns it into letters and numbers of a certain length. Hashing is used to make storing and finding information quicker because hashes are usually shorter and easier to find. Hashes also make information unreadable and so the original data can become confidential.
* The number of possible combinations of letters and numbers produced by SHA 256 exceeds the number grains of sand on Earth! That makes guessing the data hidden within the hash virtually impossible. Hashes cannot be reversed, so the process is typically used for computer security.

## Step of Hashing with SHA-256
* **Pre-processing**
 * **Padding** - If we note M the message to be hashed, and l its length in bits where l < 2⁶⁴, then as a first step we create the padded message M’, which is message M plus a right padding, such that M’ is of length l’, a multiple of 512.
 * **Blocks** - M’ is parsed into N blocks of size 512 bits, M¹ to Mᴺ, and each block is expressed as 16 input blocks of size 32 bits, M₀ to M₁₅.
 * **Hash initialization** - The initial hash value H⁰ of length 256 bits (8 input blocks of 32 bits) is set by taking the first 32 bits of the fractional parts of the square roots of the first eight prime numbers.
* **Algorithm**
 * **Message schedule** - Create a message schedule Wⁱ, consisting of four 512-bit message blocks (each made of 16 input blocks). The first block of Wⁱ is message block Mⁱ, and the next three blocks are variations of Mⁱ, obtained through the formulas mentioned in International Organization for Standardization.
 * **The big shuffle** - The input blocks of message schedule W are fed, one after the other, to a function represented below as a graph. The graph takes as inputs a hash ωⁱ(t) and a message schedule input block Wⁱ(t), and outputs a hash ωⁱ(t+1). The initial hash ωⁱ(0) fed to the graph is the intermediate hash Hⁱ⁻¹: in the case of W¹, it’s H⁰ defined in the pre-processing step. ωⁱ(0) and Wⁱ(0) produce ωⁱ(1); in turn ωⁱ(1) and Wⁱ(1) produce ωⁱ(2), etc., until ωⁱ(63) is produced.
 * **New hash** - After all input blocks from Wⁱ have been used and we ω(63) has been created, we can create the new hash Hⁱ such that each input block of Hⁱ is the sum of the corresponding input block of Hⁱ⁻¹ plus the corresponding input block of ωⁱ(63)
 
## How To Run
* **Clone repository from command prompt**
 * `git clone https://github.com/Ltrmex/SecureHashAlgorithm`
* **Change directory**
  * `cd SecureHashAlgorithm`
  * `cd sha256`
* **Compile**
  * `gcc -o sha256 sha256.c`
* **Run**
  * `./sha256 fileName.txt`

## References:
* Problem Statement
  * https://github.com/ianmcloughlin/project-thalg-2019/blob/master/project.pdf
* SHA-256
  * https://support.google.com/google-ads/answer/9004655?hl=en
  * https://decryptionary.com/dictionary/secure-hash-algorithm-256/
* Step of Hashing with SHA-256
  * https://medium.com/biffures/part-5-hashing-with-sha-256-4c2afc191c40

