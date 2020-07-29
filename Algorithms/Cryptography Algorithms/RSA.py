
# This program implements the Rivest-Shamir-Adleman (RSA) cryptosystem.
# The algorithm randomly select two prime numbers and use them 
# to generate the public and secret keys. 
# Using the keys, it can either encrypt or decrypt messages.

from cryptography_tools import gcd, xgcd
import random


# Function genetare publick key as pair (n,e) where n = pq and 
# e is a random integer number between 1 and Euler function of n :- phi(n)
# and e satisfies condition gcd(e,phi(n)) = 1.

def generate_publick_key(p, q):
	phi = (p - 1) * (q - 1)

	while True:
		e = random.randrange(2, 2024)

		if gcd(e, phi) == 1:
			return (p*q,e)


# Function genetare secret key as pair (n,d) where n = pq and 
# d is a random integer number between 1 and Euler function of n :- phi(n)
# and e satisfies condition ed = 1 (mod phi(n)).

def generate_secret_key(p, q, e):
	phi = (p - 1) * (q - 1)

	gcd, x, y = xgcd(e, phi)
	
	# make sure d is positive
	if (x < 0):
		d = x + phi
	else:
		d = x
	
	return (p*q, d)


# Function use publick key to encrypt plaintext (string) by raising each
# character's ASCII value to the power of e and taking the modulus of n.
# Return ciphertext as a string of numbres. 
# Parameter block_size refers to how many characters make up one group of 
# numbers in each index of encrypted_blocks. 
# If block_size = 2 then n must be greater than 256256.

def encryption(plaintext, publick_key, block_size = 2):
	
	n, e = publick_key
	 
	encrypted_blocks = []
	ciphertext = -1

	if len(plaintext) > 0:
		ciphertext = ord(plaintext[0])

	for i in range(1, len(plaintext)):
		if(i % block_size == 0):
			encrypted_blocks.append(ciphertext)
			ciphertext = 0

		ciphertext = ciphertext * 1000 + ord(plaintext[i])

	encrypted_blocks.append(ciphertext);

	for i in range(len(encrypted_blocks)):
		encrypted_blocks[i] = str((encrypted_blocks[i]**e) % n)

	encrypted_message = " ".join(encrypted_blocks)

	return encrypted_message


# Function use secret key to decrypts a string of numbers by raising each
# number to power of d and taking modulus of n. Return plaintext as a string.
# Parameter block_size refers to how many characters make up one group of
# numbers in each index of blocks.

def decryption(ciphertext, secret_key, block_size = 3):

	n, d = secret_key

	decrypted_blocks = [int(i) for i in ciphertext.split(' ')]

	plaintext = ""

	for i in range(len(decrypted_blocks)):

		decrypted_blocks[i] = (decrypted_blocks[i]**d) % n

		tmp = ""

		for c in range(block_size):
			tmp = chr(decrypted_blocks[i] % 1000) + tmp
			decrypted_blocks[i] //= 1000
		plaintext += tmp

	return plaintext



# Example

if __name__ == '__main__':
	
	message = """Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
	Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure 
	dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum."""

	p = 569
	q = 571
	# n = 324899

	publick_key = generate_publick_key(p,q)
	secret_key = generate_secret_key(p,q, publick_key[1])

	block_size = 2

	ciphertext = encryption(message, publick_key, block_size) 
	plaintext = decryption(ciphertext, secret_key, block_size)

	print(plaintext + "\n")
	print(ciphertext + "\n")


