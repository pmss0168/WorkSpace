package com.pmss0168.springdemo.repository;

import com.pmss0168.springdemo.entity.Permission;
import com.pmss0168.springdemo.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface PermissionRepository extends JpaRepository<Permission, String> {
}
