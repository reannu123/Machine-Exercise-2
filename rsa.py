def get_d(e,phiN):
    for d in range(99999999):
        if(e*d)%phiN == 1:
            return d

def encrypt(m,e,N):
    return (m**e)%N

def decrypt(c,d,N):
    return (c**d)%N


# Input for encryption or decryption
print("Input p and q separated by space: \n")
inputs = input().split()

p = int(inputs[0])
q = int(inputs[1])
print("Input e: \n")
e = int(input())

N = p*q
phiN = (p-1)*(q-1)

d = get_d(e,phiN)       # Private key

print("Input number of loops: \n")
loops = int(input())
for i in range(loops):
    print("Input action and message separated by space: \n")
    entry = input().split()
    choice = entry[0]
    text = int(entry[1])



    if choice == "encrypt":
        C = encrypt(text,e,N)      # Ciphertext
        print(C)

    elif choice == "decrypt":
        D = decrypt(text,d,N)      # Decrypted ciphertext
        print(D)