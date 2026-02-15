class Logger {
public:
    unordered_map<string, int> msgDict;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (this->msgDict.find(message) == this->msgDict.end()) {
            this->msgDict[message] = timestamp;
            return true;
        }
        int oldTimestamp = this->msgDict[message];
        if (timestamp - oldTimestamp >= 10) {
            this->msgDict[message] = timestamp;
            return true;
        } else
            return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */