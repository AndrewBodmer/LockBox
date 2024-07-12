def encryptNoKey(text):
    encrypted_text = ""
    i = 3
    for char in text:
        ascii_value = ord(char)
        encrypted_ascii_value = ascii_value + i
        encrypted_text += chr(encrypted_ascii_value)
        i+=1
    length = len(text)

    for i in range(int(length/2)):
        temp = encrypted_text[i]
        encrypted_text[i] = encrypted_text[length-1]
        encrypted_text[length-1] = temp

    for i in range(1, length, 2):
        temp = encrypted_text[i]
        encrypted_text[i] = encrypted_text[i-1]
        encrypted_text[i-1] = temp

    return encrypted_text

def decryptNoKey(encrypted_text):
    length = len(encrypted_text)
    decrypted_text = list(encrypted_text)

    # Reverse the second transformation
    for i in range(1, length, 2):
        temp = decrypted_text[i]
        decrypted_text[i] = decrypted_text[i-1]
        decrypted_text[i-1] = temp

    # Reverse the first transformation
    for i in range(int(length/2)):
        temp = decrypted_text[i]
        decrypted_text[i] = decrypted_text[length-1-i]
        decrypted_text[length-1-i] = temp

    decrypted_text = ''.join(decrypted_text)
    decrypted_text_result = ""

    # Reverse the initial encryption transformation
    i = 3
    for char in decrypted_text:
        ascii_value = ord(char)
        decrypted_ascii_value = ascii_value - i
        decrypted_text_result += chr(decrypted_ascii_value)
        i += 1

    return decrypted_text_result

# Test the functions
plain_text = "Hello, World!"
encrypted_text = encryptNoKey(plain_text)
print(f"Encrypted: {encrypted_text}")

decrypted_text = decryptNoKey(encrypted_text)
print(f"Decrypted: {decrypted_text}")

def main():
    plain_text = input("Enter a plain text: ")
    encrypted_text = encryptNoKey(plain_text)
    print(f"Encrypted: {encrypted_text}")
    decrypted_text = decryptNoKey(encrypted_text)
    print(f"Decrypted: {decrypted_text}")