#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ipAddresses;

        FindIpAddresses(s, ipAddresses, string(""), 0, 0);

        return ipAddresses;
    }

    void FindIpAddresses(string s, vector<string>& ipAddresses, string ipAddress, int beginId, int addressPartNum){
        if(beginId == s.length() && addressPartNum == 4){
            ipAddresses.push_back(ipAddress);
            return;
        }
        else if((beginId < s.length() && addressPartNum == 4) || (beginId >= s.length() && addressPartNum < 4)){
            return;
        }

        if(s[beginId] == '0'){
            ipAddress = (addressPartNum == 0) ? "0" : ipAddress + ".0";
            FindIpAddresses(s, ipAddresses, ipAddress, beginId + 1, addressPartNum + 1);
        }
        else{
            ipAddress = (ipAddress == "") ? ipAddress + s[beginId] : ipAddress + "." + s[beginId];
            FindIpAddresses(s, ipAddresses, ipAddress, beginId + 1, addressPartNum + 1);

            if(beginId < s.length() - 1){
                ipAddress += s[beginId + 1];
                FindIpAddresses(s, ipAddresses, ipAddress, beginId + 2, addressPartNum + 1);
            }
            
            if(beginId < s.length() - 2 && int(s[beginId] - '0') * 100 + int(s[beginId + 1] - '0') * 10 + int(s[beginId + 2] - '0') <= 255){
                ipAddress += s[beginId + 2];
                FindIpAddresses(s, ipAddresses, ipAddress, beginId + 3, addressPartNum + 1);
            }
        }
    }
};