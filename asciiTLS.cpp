#include <iostream>
#include <string>
using namespace std;
bool vowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}
string reverse(string str)
{
    int n = str.length();
    for (int i = 0; i < (n / 2); i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}
string encodePassword(const string &input)
{
    string password;
    int asciiVal = static_cast<unsigned char>(input[0]);
    string asciiStr = to_string(asciiVal);
    for (char c : input)
    {
        if (!vowel(c))
            password.push_back(c);
    }

    password = reverse(password);
    int L = static_cast<int>(password.size());
    int pos = (L + 1) / 2; // equivalent to ceil(L/2)
    password = password.substr(0, pos) + asciiStr + password.substr(pos);

    return password;
}

string decodePassword(const string &encoded)
{
    string partial;
    int asciiVal = 0;
    int n = encoded.size();
    int i = 0;

    while (i < n && !isdigit(encoded[i]))
    {
        partial.push_back(encoded[i]);
        i++;
    }
    while (i < n && isdigit(encoded[i]))
    {
        asciiVal = asciiVal * 10 + (encoded[i] - '0');
        i++;
    }
    while (i < n)
    {
        partial.push_back(encoded[i]);
        i++;
    }

    partial = reverse(partial);
    char originalFirstChar = static_cast<char>(asciiVal);
    if (partial[0] != originalFirstChar)
    {
        partial = originalFirstChar + partial;
    }
    return partial;
}
int main()
{
    int choice;
    string input;
    string encode, decode;
    cout << "1. encode word" << endl;
    cout << "2. decode a code" << endl;
    cout << "choose (1/2)" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "enter word ";
        cin >> encode;
        cout << "sandi :" << encode << " --> " << encodePassword(encode) << endl;
    }
    else if (choice == 2)
    {
        cout << "enter code ";
        cin >> decode;
        cout << "kata asli :" << decode << " --> " << decodePassword(decode) << endl;
    }
    else
        cout << "enter the valid choice!!!" << endl;

    return 0;
}