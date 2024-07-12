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