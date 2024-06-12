#include <iostream>
#include <string>
#include <vector>
#include <map>

// Tokenize user input into words
std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    for (char c : input) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

// Basic intent recognition
std::string recognizeIntent(const std::vector<std::string>& tokens) {
    static std::map<std::string, std::string> intentMap = {
        {"hello", "greeting"},
        {"hi", "greeting"},
        {"how", "question"},
        {"what", "question"},
        {"who", "question"},
        {"which", "question"},
        {"weather", "information"},
        {"news", "information"},
    };

    for (const std::string& token : tokens) {
        if (intentMap.find(token) != intentMap.end()) {
            return intentMap[token];
        }
    }
    return "unknown";
}
std::string handleResponse(const std::string& intent) {
    static std::map<std::string, std::string> responseMap = {
        {"greeting", "Hello! How can I assist you today?"},
        {"question", "Its an intresting question...."},
        {"information", "Let me provide you with some information."},
        {"unknown", "I am not sure about that"}
    };

    if (responseMap.find(intent) != responseMap.end()) {
        return responseMap[intent];
    }
    return "I'm sorry, I don't know how to respond to that.";
}
std::string analyzeSentiment(const std::string& input) {
    if (input.find("happy") != std::string::npos || input.find("good") != std::string::npos) {
        return "positive";
    }
    if (input.find("sad") != std::string::npos || input.find("bad") != std::string::npos) {
        return "negative";
    }
    return "neutral";
}
std::string answerComplexQuestion(const std::string& input) {
    if (input.find("weather") != std::string::npos) {
        return "The weather today is sunny with a slight chance of rain in the afternoon.";
    }
    if (input.find("news") != std::string::npos) {
        return "Today's news highlights include the ongoing economic summit and local sports events.";
    }
        if (input.find("how are you") != std::string::npos) {
        return "I am fine.";
    }
        if (input.find("which platform is best for codding") != std::string::npos) {
        return "Sure! there are many platform like Codealpha, W3 school, & programiz you can also get help from here.";
    }
    return "I'm sorry, I don't have the information you're looking for.";
}
int main() {
    std::string userInput;
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);
        
        if (userInput == "exit") {
            std::cout << "Chatbot: Goodbye!" << std::endl;
            break;
        }

        // Tokenize the input
        std::vector<std::string> tokens = tokenize(userInput);

        // Recognize the intent
        std::string intent = recognizeIntent(tokens);

        // Analyze sentiment
        std::string sentiment = analyzeSentiment(userInput);
        std::cout << "Chatbot (sentiment): " << sentiment << std::endl;

        // Handle the response
        std::string response = handleResponse(intent);
        if (intent == "question" || intent == "information") {
            response += " " + answerComplexQuestion(userInput);
        }

        std::cout << "Chatbot: " << response << std::endl;
    }

    return 0;
}