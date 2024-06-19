#include <iostream>
#include <list>
#include <vector>

class HashTable
{
private:
    std::vector<std::list<std::pair<int, std::string>>> table;
    int numBuckets;

    int hashFunction(int key) const
    {
        return key % numBuckets;
    }

public:
    HashTable(int numBuckets) : numBuckets(numBuckets)
    {
        table.resize(numBuckets);
    }

    void insert(int key, const std::string& value)
    {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        auto& bucket = table[index];

        for(auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if(it->first == key)
            {
                bucket.erase(it);
                return;
            }
        }
    }

    std::string search(int key) const
    {
        int index = hashFunction(key);
        const auto& bucket = table[index];

        for(const auto& pair : bucket)
        {
            if(pair.first == key)
            {
                return pair.second;
            }
        }

        return "Key not Found";
    }

    void display() const
    {
        for(int i = 0; i < numBuckets; ++i)
        {
            std::cout << "Bucket: " << i << ": ";
            for(const auto& pair : table[i])
            {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    HashTable hashTable(10);

    hashTable.insert(1, "one");
    hashTable.insert(2, "two");
    hashTable.insert(3, "thre");
    hashTable.insert(4, "four");
    hashTable.insert(5, "five");

    std::cout << "Hash Tabel:" << std::endl;
    hashTable.display();

    std::cout << std::endl;
    //search
    std::cout << "Search for key 3: " <<  hashTable.search(3) << std::endl;
    std::cout << "Search for key 6: " <<  hashTable.search(6) << std::endl;

    std::cout << std::endl;

    hashTable.remove(2);

    std::cout << "Hash Table after removing key 2: " << std::endl;
    hashTable.display();

    return 0;
}
