#include <iostream>

int strlen(const char ch[]){
    int i = 0;
    while(ch[i] != '\0')
        i++;
    return i; 
}

bool matchingBrackets(char brackets[]) {
    int counts[128] = {0};  // initialize all counts to 0
    for (int i = 0; i < strlen(brackets); i++) {
        counts[brackets[i]]++;  // increment count for bracket type
        if (counts[')'] > counts['('] || counts[']'] > counts['['] || counts['}'] > counts['{']) 
            return false;  // more RHS brackets than LHS brackets
    }
    return (counts['('] == counts[')']) && (counts['['] == counts[']']) && (counts['{'] == counts['}']);
}

int main() {
    char brackets1[] = "(){}[]";
    char brackets2[] = "(([]))";
    char brackets3[] = "({[})"; // this is false
    char brackets4[] = "({[]})()";
    
    std::cout << std::boolalpha << matchingBrackets(brackets1) << std::endl;  // true
    std::cout << std::boolalpha << matchingBrackets(brackets2) << std::endl;  // true
    std::cout << std::boolalpha << matchingBrackets(brackets3) << std::endl;  // false
    std::cout << std::boolalpha << matchingBrackets(brackets4) << std::endl;  // true
    
    return 0;
}
