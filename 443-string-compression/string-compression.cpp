class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1; // Initialize count to 1 to account for the last character
    string result;
    
    for (int i = 0; i < chars.size(); ++i) {
        if (i < chars.size() - 1 && chars[i] == chars[i + 1]) {
            // If current character is same as next character, increase count
            count++;
        } else {
            // If current character is different from next character or it's the last character
            result += chars[i]; // Append current character
            
            if (count > 1) {
                // Append count if it's greater than 1
                result += to_string(count);
            }
            
            // Reset count for the next character
            count = 1;
        }
    }
    
    chars.clear(); // Clear the original vector
    
    // Copy the compressed result back to the original vector
    for (char c : result) {
        chars.push_back(c);
    }
    
    return result.size(); // Return the size of the compressed string
}
};