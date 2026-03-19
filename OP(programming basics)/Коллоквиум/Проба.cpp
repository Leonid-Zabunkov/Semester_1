#include <functional>
#include <iostream>
#include <optional>
#include <vector>


template <typename K, typename V> class HashMap {
private:
  struct Entry {
    K key;
    V value;
    bool occupied = false;
    bool deleted = false;
  };

  std::vector<Entry> table;
  size_t count = 0;
  static constexpr size_t INITIAL_CAPACITY = 16;
  static constexpr double MAX_LOAD_FACTOR = 0.7;

  size_t hash(const K &key) const { return std::hash<K>{}(key) % table.size(); }

  void rehash() {
    std::vector<Entry> old = std::move(table);
    table.resize(old.size() * 2);
    count = 0;

    for (auto &entry : old) {
      if (entry.occupied && !entry.deleted) {
        insert(entry.key, entry.value);
      }
    }
  }

  size_t findSlot(const K &key) const {
    size_t idx = hash(key);
    size_t start = idx;

    while (table[idx].occupied) {
      if (!table[idx].deleted && table[idx].key == key) {
        return idx;
      }
      idx = (idx + 1) % table.size();
      if (idx == start)
        break;
    }
    return idx;
  }

public:
  HashMap() : table(INITIAL_CAPACITY) {}

  void insert(const K &key, const V &value) {
    if ((double)(count + 1) / table.size() > MAX_LOAD_FACTOR) {
      rehash();
    }

    size_t idx = findSlot(key);

    if (table[idx].occupied && !table[idx].deleted) {
      table[idx].value = value;
    } else {
      table[idx].key = key;
      table[idx].value = value;
      table[idx].occupied = true;
      table[idx].deleted = false;
      count++;
    }
  }

  std::optional<V> get(const K &key) const {
    size_t idx = hash(key);
    size_t start = idx;

    while (table[idx].occupied) {
      if (!table[idx].deleted && table[idx].key == key) {
        return table[idx].value;
      }
      idx = (idx + 1) % table.size();
      if (idx == start)
        break;
    }
    return std::nullopt;
  }

  bool remove(const K &key) {
    size_t idx = hash(key);
    size_t start = idx;

    while (table[idx].occupied) {
      if (!table[idx].deleted && table[idx].key == key) {
        table[idx].deleted = true;
        count--;
        return true;
      }
      idx = (idx + 1) % table.size();
      if (idx == start)
        break;
    }
    return false;
  }

  bool contains(const K &key) const { return get(key).has_value(); }

  size_t size() const { return count; }
  bool empty() const { return count == 0; }
};

int main() {
  HashMap<std::string, int> map;

  map.insert("apple", 5);
  map.insert("banana", 3);
  map.insert("orange", 7);

  std::cout << "apple: " << *map.get("apple") << std::endl;
  std::cout << "banana: " << *map.get("banana") << std::endl;

  map.insert("apple", 10);
  std::cout << "apple (updated): " << *map.get("apple") << std::endl;

  std::cout << "Contains 'orange': " << map.contains("orange") << std::endl;

  map.remove("banana");
  std::cout << "Contains 'banana' after removal: " << map.contains("banana")
            << std::endl;

  std::cout << "Size: " << map.size() << std::endl;

  return 0;
}