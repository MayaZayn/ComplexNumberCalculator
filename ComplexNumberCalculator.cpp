
#include<bits/stdc++.h>

using namespace std;

namespace AffineCipher {

// Global variables
    int a, b, c;

// Makes sure the input is only string
    string stringVerifier(string statement) {
        for (int i = 0; i < statement.size(); ++i) {
            while (!isalpha(statement[i])) {
                cout << "Please enter a valid input: " << endl;
                cin >> statement;
            }
        }
        return statement;
    }

// Makes sure the input is only numbers
    int intVerifier(int num) {
        while (!(cin >> num)) {
            cout << "Please enter a number:\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
        return num;
    }

// Validates that a & c satisfy a certain equation
    void a_c_checker(int *num1, int *num2) {
        while ((*num1 * *num2) % 26 != 1) {
            cout << "Please enter values for a and c that satisfy this equation (a * c) % 26 = 1 \n a: ";
            cin >> *num1;
            cout << "\n c: ";
            cin >> *num2;
        }
    }

    // Getting a, b, c values
    void abcInput() {
        cout << "Please enter the value of the a: " << endl;
        cin >> a;
        a = intVerifier(a);
        cout << "Please enter the value of the b: " << endl;
        cin >> b;
        b = intVerifier(b);
        cout << "Please enter the value of the c: " << endl;
        cin >> c;
        c = intVerifier(c);
        a_c_checker(&a, &c);
    }

// Ciphering the statement
    void cipherMessage() {
        string statement;
        abcInput();
        cout << "Enter the statement you want to cipher: " << endl;
        cin >> statement;
        statement = stringVerifier(statement);
        transform(statement.begin(), statement.end(), statement.begin(), ::toupper);
        for (char i: statement) {
            cout << char(((a * (i - 65) + b) % 26) + 65);
        }
        cout << endl;
    }

// Deciphering the statement
    void decipherMessage() {
        string statement;
        abcInput();
        cout << "Enter the statement you want to decipher: " << endl;
        cin >> statement;
        statement = stringVerifier(statement);
        transform(statement.begin(), statement.end(), statement.begin(), ::toupper);
        for (char i: statement) {
            int sum = (c * ((i - 65) - b));
            while (sum < 0) {
                sum += 26;
            }
            cout << char((sum % 26) + 65);
        }
        cout << endl;
    }


};

namespace CaeserCipher {

    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    void cipherMessage() {
        string text, ciphered_Message = " ";

        cout << "Enter The Message You Want to Cipher: " << endl;

        getline(cin, text); //taking the text from the user

        transform(text.begin(), text.end(), text.begin(), ::toupper); // to make the all the text an uppercase

        long long shift;

        cout << "Enter The Number Of Shifts You Like To Make To Cipher Your Message: " << endl;

        cin >> shift;

        while (shift > 26 or shift < -26)

            shift = shift % 26;

        for (int i = 0; i < text.size(); ++i) { //to loop on the text

            if (text[i] == ' ') { // to check if the current index is a character or just a space
                ciphered_Message += " ";
                continue;
            }

            for (int j = 0;
                 j < 26; ++j) { // to loop on the vector with alphabet and get the index of the character to cipher it

                if (text[i] == alphabet[j]) {
                    if (j + shift < 26 && j + shift > 0)
                        ciphered_Message += alphabet[j + shift];


                    else if (j + shift < 0)
                        ciphered_Message += alphabet[26 + (j + shift)];

                    else if (j + shift == 0)
                        ciphered_Message += alphabet[0];

                    else
                        ciphered_Message += alphabet[(j + shift) - 26];
                }


            }
        }
        cout << "The Ciphered Message is: " << ciphered_Message << endl;
    }


//
    void decipherMessage() {
        string text, deciphered_Message = " ";

        cout << "Enter The Message You Want to Decipher: " << endl;

        getline(cin, text);

        transform(text.begin(), text.end(), text.begin(), ::toupper);

        long long shift;

        cout << "Enter The Number Of Shifts You Like To Make To Decipher Your Message: " << endl;

        cin >> shift;

        while (shift > 26 or shift < -26)
            shift = shift % 26;

        for (int i = 0; i < text.size(); ++i) { //to loop on the text

            if (text[i] == ' ') {       // to check if the current index is a character or just a space
                deciphered_Message += " ";
                continue;
            }
            for (int j = 0; j <
                            26; ++j) {  // to loop on the vector with alphabet and get the index of the character to decipher it
                if (text[i] == alphabet[j]) {
                    if (j - shift < 26 and j - shift > 0)
                        deciphered_Message += alphabet[j - shift];

                    else {
                        if (j - shift < 0)
                            deciphered_Message += alphabet[26 + (j - shift)];

                        else if (j - shift == 0)
                            deciphered_Message += alphabet[0];


                        else {
                            if ((j - shift) >= 26) {
                                long long m = (j - shift) - 26;
                                deciphered_Message += alphabet[m];
                            } else
                                deciphered_Message += alphabet[26 - (j - shift)];


                        }


                    }


                }


            }
        }
        cout << "The Deciphered Message is: " << deciphered_Message << endl;
    }
}

namespace AtBashCipher {

    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> reversed_Alphabet = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K',
                                      'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A', 'z', 'y', 'x', 'w', 'v', 'u',
                                      't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e',
                                      'd', 'c', 'b', 'a'};

// Defining the Function that encrypt and decrypt the text

    void cipherMessage(bool cipher) {
        string encryptedText = "", text;
        cout << "Enter The Text You Want To " << (cipher ? "Cipher:" : "Decipher") << endl;

        getline(cin, text);  //taking the text from the user

        int text_Length = text.size();
        for (int i = 0; i < text_Length; ++i) {
            if (text[i] == ' ') encryptedText += ' ';
            else {
                for (int j = 0; j < 52; ++j) {
                    if (text[i] ==
                        alphabet[j]) {   //looping on the text to encrypt each character and add the encrypted one to an empty test
                        encryptedText += reversed_Alphabet[j];
                    }
                }
            }
        }
        cout << "Your " << (cipher ? "Encrypted" : "Decrypted") << " Message is:" << encryptedText << endl;
    }
}

namespace VignereCipher {

    void cipherMessage() {

        string keyword, text, encrypted_Text;
        encrypted_Text = "";
        cout << "Enter The Text You Want To Cipher(The Text Mustn't Be More Than 80 Character):" << endl;

        getline(cin, text);

        while (text.size() > 80) { //check if the entered text more than 80 or not
            cout << "The Text is Too Long, Enter a Text With 80 Character Maximum" << endl;
            cin.sync();
            cin.clear();
            getline(cin, text);

        }
        cout << "Enter The Keyword You Want To Cipher With(The Keyword Mustn't Be More Than 8 Character):" << endl;
        cin >> keyword;

        while (keyword.size() > 8) {   //check if the entered keyword more than 8 or not
            cout << "The Keyword is Too Long, Enter a Text With 8 Character Maximum" << endl;
            cin >> keyword;
        }

        // Tyo Change both text and keyword into uppercase characters
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

        // To Make The Keyword length = text length
        for (int i = 0; i < text.size(); ++i) {
            if (keyword.size() == text.size())
                break;
            if (i > keyword.size())
                i = 0;
            keyword += keyword[i];
        }


        for (int i = 0; i < text.size(); ++i) { //looping on the text to encrypt it
            int temp = 0;
            if (text[i] == ' ') {
                encrypted_Text += ' ';
                continue;
            }

            if (text[i] < 65 || text[i] > 90) { //checking the character in the range or not using ascii value
                encrypted_Text += text[i];
                continue;
            }
            temp += ((text[i] + keyword[i]) % 26) + 65;
            encrypted_Text += (char) temp;


        }
        cout << "Your Encrypted Text is:" << encrypted_Text << endl;
    }

    void decipherMessage() {
        string keyword, text, decrypted_Text;
        decrypted_Text = "";

        cout << "Enter The Text You Want To Decipher(The Text Mustn't Be More Than 80 Character):" << endl;

        getline(cin, text);
        while (text.size() > 80) {
            cout << "The Text is Too Long, Enter a Text With 80 Character Maximum" << endl;
            cin.sync();
            cin.clear();
            getline(cin, text);

        }
        cout << "Enter The Keyword You Want To Decipher With(The Text Mustn't Be More Than 8 Character):" << endl;
        cin >> keyword;
        while (keyword.size() > 8) {
            cout << "The Keyword is Too Long, Enter a Keyword With 8 Character Maximum" << endl;
            cin >> keyword;
        }

        // Tyo Change both text and keyword into uppercase characters
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

        // To Make The Keyword length = text length
        for (int i = 0; i < text.size(); ++i) {
            if (keyword.size() == text.size())
                break;
            if (i > keyword.size())
                i = 0;
            keyword += keyword[i];
        }


        for (int i = 0; i < text.size(); ++i) { //looping on the Text to decipher it
            int temp = 0;
            if (text[i] == ' ') {
                decrypted_Text += ' ';
                continue;
            }

            if (text[i] < 65 || text[i] > 90) { //checking the character in the range or not using ascii value
                decrypted_Text += text[i];
                continue;
            }
            temp += (((text[i] - keyword[i]) + 26) % 26) + 65; //deciphering the character
            decrypted_Text += (char) temp;


        }
        cout << "Your Decrypted Text is:" << decrypted_Text << endl;
    }
}

namespace BaconianCipher {

    map<char, string> cipherMap{
            {'A', "aaaaa"},
            {'B', "aaaab"},
            {'C', "aaaba"},
            {'D', "aaabb"},
            {'E', "aabaa"},
            {'F', "aabab"},
            {'G', "aabba"},
            {'H', "aabbb"},
            {'I', "abaaa"},
            {'J', "abaab"},
            {'K', "ababa"},
            {'L', "ababb"},
            {'M', "abbaa"},
            {'N', "abbab"},
            {'O', "abbba"},
            {'P', "abbbb"},
            {'Q', "baaaa"},
            {'R', "baaab"},
            {'S', "baaba"},
            {'T', "baabb"},
            {'U', "babaa"},
            {'V', "babab"},
            {'W', "babba"},
            {'X', "babbb"},
            {'Y', "bbaaa"},
            {'Z', "bbaab"}};

    map<string, char> decipherMap;

    void initDecipherMap() {
        for (auto[letter, cipherCode]: cipherMap)
            decipherMap[cipherCode] = letter;
    }

    void decipherMessage() {
        initDecipherMap();
        string userInput, decipheredMessage;
        cout << "Enter a message you would like to decipher:" << endl;
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        for (int i = 0; i < userInput.length(); i += 5) {
            decipheredMessage += decipherMap[userInput.substr(i, 5)];

            if (userInput[i + 5] == ' ') {
                decipheredMessage += ' ';
                i++;
            }

        }
        cout << "The deciphered message is: " + decipheredMessage << endl;
    }

    void cipherMessage() {
        string userInput, cipheredMessage;
        cout << "Enter a message you would like to cipher:" << endl;
        getline(cin, userInput);
        for (char i: userInput)
            if (i == ' ')
                cipheredMessage += " ";
            else
                cipheredMessage += cipherMap[toupper(i)];

        cout << "Ciphered message: " + cipheredMessage << endl;
    }

}
namespace SubstitutionCipher {

    void decipherMessage() {
        string userInput, decipheredMessage, key, cipheredAlpha;
        cout << "Enter a message you would like to decipher:" << endl;
        getline(cin, userInput);

        cout << "Cipher key (5 unique letters):" << endl;
        getline(cin, key);

        cipheredAlpha += key;
        for (int i = 'a'; i <= 'z'; i++)
            if (key.find(tolower((char) i)) == string::npos)
                cipheredAlpha += (char) i;
        cout << cipheredAlpha << endl;

        for (char i: userInput)
            decipheredMessage += (isalpha(i) ? (char) (cipheredAlpha.find(tolower(i)) + 'a') : i);

        cout << "The deciphered message is: " + decipheredMessage << endl;
    }

    void cipherMessage() {
        string userInput, cipheredMessage, key, cipheredAlpha;
        cout << "Enter a message you would like to cipher:" << endl;
        getline(cin, userInput);

        cout << "Cipher key (5 unique letters):" << endl;
        getline(cin, key);

        cipheredAlpha += key;
        for (int i = 'a'; i <= 'z'; i++)
            if (key.find(tolower((char) i)) == string::npos)
                cipheredAlpha += (char) i;
        cout << cipheredAlpha << endl;

        for (char i: userInput)
            cipheredMessage += (isalpha(i) ? cipheredAlpha[tolower(i) - 'a'] : i);

        cout << "Ciphered message: " + cipheredMessage << endl;
    }
}

namespace PolybiusCipher {
//Cipher and decipher maps, which will be initialised depending on the key
    map<char, string> cipherMap;
    map<string, char> decipherMap;

/**
 * Map initialising function using the key sent as a parameter.
 * cipher is a boolen parameter to check if this map is a cipherMap or a decipherMap
 * It loops over every position possible in a 5x5 table (00, 01, etc.) and uses this equation (j + i * 5 + 'a')
 * to determine the character we should map this index to.
 * In the case cipher is true, we insert the characterIndex we calculated mapped to the row+column string value
 * For eg. 'a' : "55" in the case that the row is 5, and column is 5 (first digit in the key is 5).
 * In the case the cipher is false, each row+column string value is mapped to the character.
 * For eg. "55" : "a" in the case that the row is 5, and column is 5 (first digit in the key is 5).
*/
    void initMap(string key, bool cipher) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                string row = to_string(key[i] - '0'), column = to_string(key[j] - '0');
                int charIndex = j + i * 5 + 'a';
                if (cipher)
                    cipherMap.insert({(char) (charIndex > 'i' ? charIndex + 1 : charIndex), row + column});
                else
                    decipherMap.insert({row + column, (char) (charIndex > 'i' ? charIndex + 1 : charIndex)});
            }
        }
    }

/**
 * Function that handles taking the input and deciphering the message.
 * It takes a string from a user, and a key, and calls initMap function with
 * the key and cipher = false. Then it loops over the string and checks for every
 * two consecutive digits and checks for their representation(value) in the decipherMap
 * and adds it to decipheredMessage. If a space is found, it adds the space to the
 * decipheredMessage string and adds one to the iterator value i.
 */
    void decipherMessage() {
        string userInput, decipheredMessage, key, decipheredAlpha;
        cout << "Enter a message you would like to decipher:" << endl;

        getline(cin, userInput);

        cout << "Cipher key (5 numbers, eg: 51432):" << endl;
        getline(cin, key);
        while (key.size() != 5 || to_string(stoi(key)) != key) {
            cout << "Cipher key must be 5 digits next to each other.\nCipher key (5 numbers, eg: 51432):" << endl;
            getline(cin, key);
        }

        initMap(key, false);

        for (int i = 0; i < userInput.size(); i += 2) {
            string currTwoDigits = userInput.substr(i, 2);
            if (isdigit(currTwoDigits[0]) && isdigit(currTwoDigits[1]))
                decipheredMessage += decipherMap[currTwoDigits];
            else
                decipheredMessage += currTwoDigits;
            if (userInput[i + 2] == ' ') {
                decipheredMessage += ' ';
                i++;
            }
        }

        cout << "The deciphered message is: " + decipheredMessage << endl;
    }

/**
 * Function that handles taking the input and ciphering the message.
 * It takes a string from a user, and a key, and calls initMap function with
 * the key and cipher = true. Then it loops over the string and checks for every
 * letter, and checks for their representation(value) in the cipherMap and adds it to cipheredMessage.
 * If the letter is found, it adds value found in the map, else, it adds the character itself.
 */
    void cipherMessage() {
        string userInput, cipheredMessage, key;
        cout << "Enter a message you would like to cipher:" << endl;

        getline(cin, userInput);

        cout << "Cipher key (5 numbers, eg: 51432):" << endl;
        getline(cin, key);
        while (key.size() != 5 || to_string(stoi(key)) != key) {
            cout << "Cipher key must be 5 digits next to each other.\nCipher key (5 numbers, eg: 51432):" << endl;
            getline(cin, key);
        }

        initMap(key, true);

        for (char i: userInput)
            if (isalpha(i))
                cipheredMessage += cipherMap[tolower(i == 'j' ? 'i' : i)];
            else
                cipheredMessage += i;

        cout << "Ciphered message: " + cipheredMessage << endl;
    }
}

namespace MorseCipher {
    map<char, string> cipherMap = {{'a', ".-"},
                                   {'b', "-..."},
                                   {'c', "-.-."},
                                   {'d', "-.."},
                                   {'e', "."},
                                   {'f', "..-."},
                                   {'g', "--."},
                                   {'h', "...."},
                                   {'i', ".."},
                                   {'j', ".---"},
                                   {'k', "-.-"},
                                   {'l', ".-.."},
                                   {'m', "--"},
                                   {'n', "-."},
                                   {'o', "---"},
                                   {'p', ".--."},
                                   {'q', "--.-"},
                                   {'r', ".-."},
                                   {'s', "..."},
                                   {'t', "-"},
                                   {'u', "..-"},
                                   {'v', "...-"},
                                   {'w', ".--"},
                                   {'x', "-..-"},
                                   {'y', "-.--"},
                                   {'z', "--.."},
                                   {'0', "-----"},
                                   {'1', ".----"},
                                   {'2', "..---"},
                                   {'3', "...--"},
                                   {'4', "....-"},
                                   {'5', "....."},
                                   {'6', "-...."},
                                   {'7', "--..."},
                                   {'8', "---.."},
                                   {'9', "----."}};

    map<string, char> decipherMap;

    void initDecipherMap() {
        for (auto[letter, morse]: cipherMap)
            decipherMap[morse] = letter;
    }

    void decipherMessage() {
        initDecipherMap();
        string userInput, decipheredMessage;
        int lastIndex = 0;
        cout << "Enter a message you would like to decipher:" << endl;
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        for (int i = 0; i < userInput.length(); i++) {
            if (userInput[i] == ' ' || i == userInput.length() - 1) {
                decipheredMessage += decipherMap[userInput.substr(lastIndex,
                                                                  (i == userInput.length() - 1 ? i + 1 : i) -
                                                                  lastIndex)];
                lastIndex = i + 1;
                if (userInput[i] == ' ' && userInput[i + 1] == ' ' && userInput[i + 2] == ' ') {
                    decipheredMessage += " ";
                    i += 2;
                    lastIndex += 2;
                }
            }
        }
        cout << "The deciphered message is: " + decipheredMessage << endl;
    }

    void cipherMessage() {
        string userInput, cipheredMessage;
        cout << "Enter a message you would like to cipher:" << endl;
        getline(cin, userInput);
        for (char i: userInput)
            if (i == ' ')
                cipheredMessage += "  ";
            else
                cipheredMessage += cipherMap[tolower(i)] + " ";

        cout << "Ciphered message: " + cipheredMessage << endl;
    }

}

namespace XORCipher {
    string hexForm;
    unsigned long num;

// Makes sure the input is only string
    string stringVerifier(string statement) {
        for (int i = 0; i < statement.size(); ++i) {
            while (!isalpha(statement[i])) {
                cout << "Please enter a valid input: " << endl;
                cin >> statement;
            }
        }
        return statement;
    }

// Makes sure the input is only hexadecimal
    string hexVerifier(string statement) {
        for (int i = 0; i < statement.size(); ++i) {
            while (!isdigit(statement[i]) && statement[i] != 'a' && statement[i] != 'b' && statement[i] != 'c' &&
                   statement[i] != 'd' && statement[i] != 'e' && statement[i] != 'f') {
                cout << "Please enter a valid input: " << endl;
                cin >> statement;
            }
        }
        return statement;
    }

// Ciphering the message
    void cipherMessage() {
        string statement;
        char secretKey;
        cout << "Please enter a statement: " << endl;
        cin >> statement;
        stringVerifier(statement);
        cout << "Please enter the secret key: " << endl;
        cin >> secretKey;
        cout << "The statement ciphered in characters: " << endl;
        for (char j: statement) {
            cout << (char) (secretKey ^ j);
        }
        cout << "The statement ciphered in hexadecimal form: " << endl;
        for (char i: statement) {
            cout << setw(2) << setfill('0') << hex << (secretKey ^ i);
        }
        cout << endl;
    }

// Deciphering the message
    void decipherMessage() {
        string statement;
        char secretKey;
        cout << "Please enter the hexadecimal ciphered message: " << endl;
        cin >> statement;
        statement = hexVerifier(statement);
        transform(statement.begin(), statement.end(), statement.begin(), ::tolower);
        cout << "Please enter the secret key: " << endl;
        cin >> secretKey;
        for (int i = 0; i < statement.size(); i += 2) {
            string frst(1, statement[i]);
            string scnd(1, statement[i + 1]);
            hexForm = frst + scnd;
            num = stoi(hexForm, nullptr, 16);
            cout << (char) (num ^ secretKey);
        }
        cout << endl;
    }

}

namespace RailFenceCipher {
    void cipherMessage() {
        string statement;
        getline(cin, statement);
        statement.erase(remove(statement.begin(), statement.end(), ' '), statement.end()); // Removing spaces
        for (int j = 0; j < statement.size(); j += 4) {
            cout << statement[j];
        }
        for (int j = 1; j < statement.size(); j += 2) {
            cout << statement[j];
        }
        for (int j = 2; j < statement.size(); j += 4) {
            cout << statement[j];
        }
        cout << endl;
    }

// Deciphering Function
    void decipherMessage() {
        string statement;
        getline(cin, statement);
        char board[3][statement.size()];
        bool down;
        int row = 0, column = 0, indx = 0;

        // Creating a rail board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < statement.size(); ++j) {
                board[i][j] = '-';
            }
        }

        // Filling letters' places with '*'
        for (int i = 0; i < statement.size(); ++i) {
            if (row == 2)
                down = false;
            if (row == 0)
                down = true;
            board[row][column++] = '*';
            down ? row++ : row--;
        }

        // Placing letters in their correct places
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < statement.size(); ++j) {
                if (board[i][j] == '*' && indx < statement.size())
                    board[i][j] = statement[indx++];
            }
        }
        row = 0, column = 0;

        // Displaying the deciphered message
        for (int i = 0; i < statement.size(); ++i) {
            if (row == 2)
                down = false;
            if (row == 0)
                down = true;
            cout << board[row][column++];
            down ? row++ : row--;
        }
        cout << endl;
    }
}

/**
 * Function that handles taking the operation input from the user
 */
int getInput() {
    int cipher;
    cout << "\nAhlan ya user ya habibi.\n"
            "Which cipher would you like to use today?\n"
            "1- Affine Cipher\n"
            "2- Caeser Cipher\n"
            "3- AtBash Cipher\n"
            "4- Vignere Cipher\n"
            "5- Baconian Cipher\n"
            "6- Simple Substitution Cipher\n"
            "7- Polybius Square Cipher\n"
            "8- Morse Code Cipher\n"
            "9- XOR Cipher\n"
            "10- Rail-fence Cipher\n"
            "99- Exit\n"
            ">>\n";
    cin >> cipher;
    return cipher;
}


/**
 * Function that handles taking the operation input from the user
 */
void promptCipherOptions(int cipherNumber) {
    while (true) {
        int operation;
        cout << "\nWhat do you like to do today?\n"
                "1- Cipher a message\n"
                "2- Decipher a message\n"
                "3- Exit\n"
                ">>\n";
        cin >> operation;
        cin.clear();
        cin.sync();
        bool cipher = operation == 1;
        if (cipher || operation == 2) {
            switch (cipherNumber) {
                case 1:
                    cipher ? AffineCipher::cipherMessage() : AffineCipher::decipherMessage();
                    break;
                case 2:
                    cipher ? CaeserCipher::cipherMessage() : CaeserCipher::decipherMessage();
                    break;
                case 3:
                    cipher ? AtBashCipher::cipherMessage(true) : AtBashCipher::cipherMessage(false);
                    break;
                case 4:
                    cipher ? VignereCipher::cipherMessage() : VignereCipher::decipherMessage();
                    break;
                case 5:
                    cipher ? BaconianCipher::cipherMessage() : BaconianCipher::decipherMessage();
                    break;
                case 6:
                    cipher ? SubstitutionCipher::cipherMessage() : SubstitutionCipher::decipherMessage();
                    break;
                case 7:
                    cipher ? PolybiusCipher::cipherMessage() : PolybiusCipher::decipherMessage();
                    break;
                case 8:
                    cipher ? MorseCipher::cipherMessage() : MorseCipher::decipherMessage();
                    break;
                case 9:
                    cipher ? XORCipher::cipherMessage() : XORCipher::decipherMessage();
                    break;
                case 10:
                    cipher ? RailFenceCipher::cipherMessage() : RailFenceCipher::decipherMessage();
                    break;
                default:
                    break;
            }
        } else if (operation == 3)
            break;
        else
            cout << "Please enter a valid operation..";
    }
}

int main() {
    bool running = true;
    while (running) {
        int cipherChoice = getInput();
        cin.clear();
        cin.sync();
        if (cipherChoice >= 1 && cipherChoice <= 10)
            promptCipherOptions(cipherChoice);
        else if (cipherChoice == 99) {
            cout << "\nSalam Hapipi.";
            running = false;
        } else
            cout << "Please enter a valid operation..";
    }
    return 0;
}