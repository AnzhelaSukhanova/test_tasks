#include <iostream>
#include <map>
#include <cassert>

using namespace std;

template<class Key, class Value>
class dictionary
{
public:
	virtual ~dictionary() = default;

	virtual const Value& get(const Key& key) = 0;
	virtual void set(const Key& key, const Value& value) = 0;
	virtual bool is_set(const Key& key) = 0;
};

template<class Key, class Value>
class map_dictionary : public dictionary<Key, Value>
{
private:
	std::map<Key, Value> dict;
public:
	bool is_set(const Key& key) override
	{
		return this->dict.contains(key);
	}

	const Value& get(const Key& key) override
	{
		if (this->is_set(key))
			return this->dict[key];
		else
		{
			auto default_value = new Value();
			return *default_value;
		}
	}

	void set(const Key& key, const Value& value) override
	{
		this->dict[key] = value;
	}
};


template<class Key>
class not_found_exception : public std::exception
{
public:
	virtual const Key& get_key() const noexcept = 0;
};

int main()
{
	map_dictionary<int, int> dict;
	for (int i = 0; i < 5; ++i)
		dict.set(i, i^2);
	for (int i = 0; i < 5; ++i)
		assert (dict.get(i) == (i^2));
	return 0;
}
