package com.pmss0168.springdemo.repository;

import com.pmss0168.springdemo.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User, String> {
    public boolean existsByUsername(String username);
}
