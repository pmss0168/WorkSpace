package com.pmss0168.springdemo.service;

import com.pmss0168.springdemo.dto.request.APIResponse;
import com.pmss0168.springdemo.dto.request.PermissionRequest;
import com.pmss0168.springdemo.dto.response.PermissionResponse;
import com.pmss0168.springdemo.entity.Permission;
import com.pmss0168.springdemo.mapper.PermissionMapper;
import com.pmss0168.springdemo.repository.PermissionRepository;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class PermissionService {
    PermissionRepository permissionRepository;
    PermissionMapper permissionMapper;

    public PermissionResponse createPermission(PermissionRequest request) {
        Permission permission = permissionMapper.toUser(request);
        permission = permissionRepository.save(permission);
        return permissionMapper.toUserResponse(permission);
    }

    public List<PermissionResponse> getAllPermissions() {
        var permissions = permissionRepository.findAll();
        return permissions.stream().map(permissionMapper::toUserResponse).toList();
    }

    public void deletePermission(String permissionId) {
        permissionRepository.deleteById(permissionId);
    }
}
