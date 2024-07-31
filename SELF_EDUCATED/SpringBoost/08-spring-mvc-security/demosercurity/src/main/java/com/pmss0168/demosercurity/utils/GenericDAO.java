package com.pmss0168.cruddemo.utils;

import java.util.List;

public interface GenericDAO<T> {
    List<T> findAll();
    T findById(int ID);
    T save(T t);
    void deleteById(int Id);
}
