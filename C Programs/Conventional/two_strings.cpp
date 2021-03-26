# include <iostream>
# include <vector>
# include <string>
# include "singly_linked_list_3.cpp"
using namespace std;




int hashFunction(char str){
    return (int)str;
}

string twoStrings(string s1, string s2) {
    // Making the hashmap.
    char hash_map[256];

    // Polulating the hashmap.
    for (int i = 0; i < s1.length(); i++)
    {
        // Calculating hash and putting value in hash table
        int hash=hashFunction(s1[i]);
        hash_map[hash]=s1[i];

    }
    // Doing comparison with the other string.
    for (int i = 0; i < s2.length(); i++)
    {
        // Getting the hash
        int hash=hashFunction(s2[i]);
        if (hash_map[hash]==s2[i]){
            return "YES";
        }
    }
    return "NO";
}


int main(){
    
    string arr1={"akhmlhkvkgifrzteluvtxozdzubndlofrmkfbhykpoftuxanpbpjtirjafczsgdwabyiglxxqoybgyjzeysysfsrqwtsdboahbedvxfgsecnwedpnavdplzgrhlljtazfmvsskfdizvqsyttcgjsmegevzhcjvjajhejyjjmgmxbvowcethwfetdtcnrehwvxswhhaunmxfevefwmxkdfduvwhouihwbybjbzvftlkxyqcwnzsvhtubfngdgqqckemchqmjzvqaxslfslhqpakrvvdlkcmstmkgixpzdcqzrhmbvqemrvumskelnjewrotbxoblsgrwwfjhgjgdsmgougrilnypahdzbcxlqjipxjsbodijlupmwfqbvexliinvvtqnkbnntyzuehiednnmipcjshdqlvfoggvqwjwrevsahailkvwumyxmaaluceuxebsmajghuazflafyfkvslrvixthqzjjpbtkzygxendcrcxiqzlntxdxwkkjggkvnvkonbtwxzillgooeglptbdgnerxnebufesbooaamtovtnqtakytiasbrwztadidctxebyxijuwdcesjmcloexorzubpcniakujoymddhxydciliuesdymhiapjflaqnezbjxxlkwdklxmkwupewetsomwcxjhnaiyivlwuqcvcasgfdjmeziyyxzpjfpyiaqxjhmcdaodfzvzasvmffnqdzwygmiexdynpygariejxfbbtzqoivfvvhxqflwrshyxyyjzdosnnhkcoxxiyqmmxrfspzfouvhktrirnhubhrkwhkgwozhcswlgutidyanbjwnbykrrrmnbqkksdrosihupxicpmdtudocqxmbqziwrggyoucqqboykzwsmcgfvncckomscrpjeskcnakitikjwxhonunxbiqlwlexfjuphkyizrocqpvrajpnx"};

    string arr2={"bdsyakcbmwqxpxezqjvhgtmeiosnzkvdfcqvhsbxbwjkliqgjqghnhhuqipoujyervbiedrrijvyqdldgahihygfvrgrznfwarenoopadpcyklrdgvaxumgaqftbxzhqmjoyansyrisizsrbmemzcexbyvfphgyuevbtxzhfelrvnsjggjguikgihaktstlwnjalswntgtbuwxeobbamqnpeuyzlqekodxpwfncpvvjlruedimkeyrzulzlujzslpgzckcewptdbsymwxajwoduyadioedqrivynyluxrrnxgnxrhaawrmjdjstshvoalbbcsnljokjxddshemgzxvdwhtirvqfqatmrriitbsqqbuaijcadxxwvhljgdbhwoeyubidwyotntqqniipxxqwhhdiklxalgdxbakhcspvvajeksvdnwboofuqswfgwyfphkidkaesyqxwoaenmfkrtjuhbsqeubrnwhrkkcmnsrkdxasqbggeelihesfttztfdrqprmwnihvbjcppphfmjvoarsxvsfrsontpyvzgmrvesugdkqcxvrjyrrxdmpeadscxtuptherqkyytlufepjfkmkswbrlosyzouisliwddsvkxtisgsqxgadybzintzndjorccyrcgfpajwuutprhplzwpizzkggbgmnxxtrjrxnxldjfmbenhdzjjarpzaisehejgxejxdzvesafkvtvhgphafwtoiekvlawepmgjofyqjxzkzsdyeyqfenplhhsaxdpewpcclphglfrxunxuaycujzteyqcypohvyxlbuaugfcgiwmpimsqxayivaazxaoisoukipqpxkcivicevsorfoajbntsfhiologjjwwolwwbpvexuwipqomgclpfjxlcq"};

    cout<<twoStrings(arr1,arr2)<<endl;
    
    
    



    return 0;
}