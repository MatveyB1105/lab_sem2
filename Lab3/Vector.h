#pragma once
#include "DynamicArray.h"
#include <math.h>
template <typename T> class Vector {
private:
    DynamicArray<T>* vector;
public:
    Vector() {
		this->vector = new DynamicArray<T>();
    }

    Vector(T* other, int count) { 
		this->vector = new DynamicArray<T>(other, count);
	}

	Vector(int size) { 
		this->vector = new DynamicArray<T>(size);
	}

	Vector(const Vector<T>& other) {  
		this->vector = new DynamicArray<T>(*other.vector);
	}
    
	T& Get(const int index) const {
        return this->vector->Get(index);
	}

    const T& GetFirst() const {
        return this->Get(0);
    }

    const T& GetLast() const {
        return this->Get(this->GetLength()-1);
    }

    const int GetLength() const { 
	    return this->vector->GetSize();
	}

    void Append(T item) {
	    this->vector->Set(this->GetLength()-1, item);
	}

	void Prepend(T item) {
		this->vector->Set(0, item);
	}

	void InsertAt(int index, T item) {
		this->vector->Set(index, item);
	}

	Vector <T>* Map(T (*func)(T)) {
		Vector <T>* result = new Vector<T>(this->GetLength()); 
		for (int i = 0; i < this->GetLength(); i++) {
            result->InsertAt(func(this->Get(i)));
        }
		return result;
	}

	Vector<T>* VectorSum(const Vector<T>* other) {
		if(this->GetLength() != other->GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		Vector<T>* result = new Vector<T>(this->GetLength());
		for(int i = 0; i < this->GetLength(); i++) {
			result->Set(i, this->Get(i) + other->Get(i));
		}
		return result;
	}

	void VectorScal(T scalar) {
		for(int i = 0; i < this->GetLength(); i++) {
			this->vector->Set(i, this->Get(i)*scalar);
		}
	}

	T Norm() {
		T result = T();
		for(int i = 0; i < this->GetLength(); i++) {
			result += this->Get(i) * this->Get(i);
		}
		return sqrt(result);
	}

	T ScalarMult(const Vector<T>* other) {
		if(this->GetLength() != other->GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		T result = T();
		for(int i = 0; i < this->GetLength(); i++) {
			result+= this->Get(i) * other->Get(i);
		}
		return result;
	}

	T& operator [](int index) const {
		if(index < 0 || index >= this->GetLength() ) {
			throw std::out_of_range("Out of range");
		}
		return this->Get(index);
	}

	friend Vector<T> operator *(const T& scalar, const Vector<T>& vec) {
		Vector<T> result = vec;
		for(int i = 0; i < result.GetLength(); i++) {
			result.vector->Set(i, vec.Get(i)*scalar);
		}
		return result;
	}

	friend Vector<T> operator *(const Vector<T>& vec, const T& scalar){
		Vector<T> result = vec;
		for(int i = 0; i < result.GetLength(); i++) {
			result.vector->Set(i, vec.Get(i)*scalar);
		}
		return result;
	}

	friend Vector<T> operator +(const Vector<T>& vec, const Vector<T>& vec2) {
		Vector<T> result = vec;
		for(int i = 0; i < result.GetLength(); i++) {
			result.vector->Set(i, vec.Get(i)+vec2.Get(i));
		}
		return result;
	}

	Vector<T>& operator =(const Vector<T>& other) {
		if(this->GetLength() != other.GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		for(int i = 0; i < this->GetLength(); i++) {
			this->vector->Set(i, other.Get(i));
		}
		return *this;
	}

	Vector<T>& operator =(Vector<T>&& other) {
		if(this->GetLength() != other.GetLength()) {
			throw std::logic_error("Lengths of vectors are not equal");
		}
		for(int i = 0; i < this->GetLength(); i++) {
			this->vector->Set(i, std::move(other.Get(i)));
		}
		return *this;
	}

	friend std::ostream& operator << (std::ostream& stream, const Vector<T>& vec) {
		stream << "{";
		for(int i = 0; i < vec.GetLength() - 1; i++) {
        stream << vec.Get(i) << ", ";
    	}
		stream << vec.GetLast() << "}" << std::endl;
		return stream;
    }
    
};