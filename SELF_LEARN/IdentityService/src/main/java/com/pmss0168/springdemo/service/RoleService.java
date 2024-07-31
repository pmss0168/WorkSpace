package com.pmss0168.springdemo.service;

import com.pmss0168.springdemo.dto.request.RoleRequest;
import com.pmss0168.springdemo.dto.response.RoleResponse;
import com.pmss0168.springdemo.mapper.RoleMapper;
import com.pmss0168.springdemo.repository.PermissionRepository;
import com.pmss0168.springdemo.repository.RoleRepository;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.stereotype.Service;

import java.util.HashSet;
import java.util.List;

@Service
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class RoleService {
    RoleRepository roleRepository;
    RoleMapper roleMapper;
    PermissionRepository permissionRepository;

    public RoleResponse create(RoleRequest request) {
        var role = roleMapper.toRole(request);
        var permissions = permissionRepository.findAllById(request.getPermissions());
        role.setPermissions(new HashSet<>(permissions));
        return roleMapper.toRoleResponse(roleRepository.save(role));
    }

    public List<RoleResponse> getAll(){
        return roleRepository.findAll()
                .stream()
                .map(roleMapper::toRoleResponse)
                .toList();
    }

    public void deleteById(String roleId) {
        roleRepository.deleteById(roleId);
    }
}
