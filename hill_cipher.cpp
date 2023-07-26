#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get the plaintext message from the user.
  string plaintext;
  cout << "Enter the plaintext message: ";
  getline(cin, plaintext);

  // Get the key from the user.
  string key;
  cout << "Enter the key: ";
  getline(cin, key);

  // Check if the key is invertible.
  bool invertible = true;
  for (int i = 0; i < key.length(); i++) {
    for (int j = i + 1; j < key.length(); j++) {
      if (key[i] == key[j]) {
        invertible = false;
        break;
      }
    }
    if (!invertible) {
      break;
    }
  }

  // If the key is not invertible, print an error message and exit.
  if (!invertible) {
    cout << "The key is not invertible." << endl;
    return 1;
  }

  // Convert the key to a matrix.
  int keyMatrix[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      keyMatrix[i][j] = key[i * 3 + j] - 'A';
    }
  }

  // Encrypt the plaintext message.
  string ciphertext;
  for (int i = 0; i < plaintext.length(); i += 3) {
    // Convert the plaintext block to a vector.
    int plaintextBlock[3];
    for (int j = 0; j < 3; j++) {
      plaintextBlock[j] = plaintext[i + j] - 'A';
    }

    // Multiply the plaintext block by the key matrix.
    int ciphertextBlock[3];
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ciphertextBlock[j] += plaintextBlock[k] * keyMatrix[j][k];
      }
      ciphertextBlock[j] %= 26;
    }

    // Convert the ciphertext block to a string.
    char ciphertextChar[3];
    for (int j = 0; j < 3; j++) {
      ciphertextChar[j] = ciphertextBlock[j] + 'A';
    }

    // Add the ciphertext block to the ciphertext string.
    ciphertext += ciphertextChar;
  }

  // Print the ciphertext message.
  cout << "The ciphertext message is: " << ciphertext << endl;

  return 0;
}
