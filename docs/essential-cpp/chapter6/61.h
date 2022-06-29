template <typename elemType>
class example {
public:
    example(const elemType &min, const elemType &max);
    example(const elemType *array, int size);

    elemType& operator[](int index);
    bool operator==(const example1&) const;

    bool insert(const elemType*, int);
    bool insert(const elemType&);

    elemType min() const {
        return _min;
    }
    elemType max() const {
        return _max;
    }

    void min(const elemType&);
    void max(const elemType&);

    int count(const elemType &value) const;

private:
    int _size;
    elemType *_parray;
    elemType _min;
    elemType _max;
};
