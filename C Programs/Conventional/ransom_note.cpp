# include <iostream>
# include <vector>
# include "singly_linked_list_3.cpp"
using namespace std;




int hashFunction(string str){
    int hash=0;
    for (int i = 0; i < str.length(); i++)
        hash+=int(str[i]);
    hash=hash%10;
    return hash;
}

void checkMagazine(vector <string> magazine, vector<string> note){
    // Making hash map from the magazine array.
    singly_linked_list_3 *hash_map[10];
    for (int i = 0; i < 10; i++)
        hash_map[i]=NULL;

    // Populating the hashmap.
    for (int i = 0; i < magazine.size(); i++)
    {
        int hash=hashFunction(magazine[i]);
        hash_map[hash]=hash_map[hash]->add_data(magazine[i]);
    }
    
    // Iterating the note array.
    for (int i = 0; i < note.size(); i++)
    {
        int hash=hashFunction(note[i]);
        // If the note has something which is not in magazine.
        if (hash_map[hash]->search(note[i])==false){
            cout<<"No"<<endl;
            return;
        }
        // For note word matching magazine word.
        hash_map[hash]->remove_data(note[i]);
    }
    cout<<"Yes"<<endl;
    
}


int main(){
    
    vector <string> arr1={"zahk","dp","apdz","clo","e","dk","awfvf","osb","qr","sa","cqjq","zgr","nvxtb","abjy","axa","ili","wdyw","soqku","buwcl","qcub","sautu","ii","vkrzl","bdob","nona","al","zg","ombzc","c","dbun","f","xkuo","lsax","hfki","j","dfft","uce","ugj","ywz","vucgg","xq","udrkt","ypy","tmxgc","ty","gar","kty","dc","bznj","pzzx","clo","apdz","nvxtb","clo","sa","clo","zahk","awfvf","soqku","udrkt","udrkt","e","ypy","xkuo","tmxgc","ombzc","wdyw","al","axa","lsax","clo","abjy","osb","apdz","bdob","pzzx","zahk","c","bznj","gar","osb","xkuo","zahk","zg","uce","zg","clo","e","apdz","gar","xq","dbun","buwcl","ili","bznj","clo","osb","dc","dbun","ywzz"};

    vector <string> arr2={"buwcl","qr","axa","ypy","zahk","nvxtb","dp","hfki","ii","uce","dc","zg","dbun","ypy","ty","cqjq","zg","kty","bznj","zg","zahk","dp","c","al","ugj","ywz","qcub","ywz","wdyw","hfki","gar","e","axa","dp","qr","kty","bznj","clo","ty","vucgg","qcub","al","vkrzl","qcub","j","awfvf","soqku","lsax","bdob","nvxtbb"};

    checkMagazine(arr1,arr2);

    



    return 0;
}