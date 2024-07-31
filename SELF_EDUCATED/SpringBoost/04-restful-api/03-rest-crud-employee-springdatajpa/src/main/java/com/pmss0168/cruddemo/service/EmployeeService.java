package com.pmss0168.cruddemo.service;

import com.pmss0168.cruddemo.entity.Employee;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface mployeeService {
    List<Employee> findAll();
    Employee findById(int id);
    Employee save(Employee employee);
    void deleteById(int id);
}
