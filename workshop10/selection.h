namespace sdds {
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], keyType key, size_t size) {
        int* result = new int[size + 1];//size+1 for -1
        int noOfResult = 0;
        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                //storing matches
                result[noOfResult++] = i;
            }
        }
        //End of the indice
        result[noOfResult] = -1;
        return result;
    }

    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
        std::cout << title << std::endl;
        if (indices != nullptr && indices[0] != -1) {
            for (int i = 0; indices[i] != -1; i++) {
                //display comma when it is not first
                if (i > 0) {
                    std::cout << ", ";
                }
                std::cout << array[indices[i]];
            }
        }
        else {
            std::cout << "Empty Selection" << std::endl;
        }
        std::cout << std::endl;
    }
}
