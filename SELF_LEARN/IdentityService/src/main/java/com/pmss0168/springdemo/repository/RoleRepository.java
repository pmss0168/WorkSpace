package com.pmss0168.springdemo.repository;

import com.pmss0168.springdemo.entity.Permission;
import com.pmss0168.springdemo.entity.Role;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface RoleRepository extends JpaRepository<Role, String> {
}
