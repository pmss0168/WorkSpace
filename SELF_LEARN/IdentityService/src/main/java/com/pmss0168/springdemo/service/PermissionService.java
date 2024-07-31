package com.pmss0168.springdemo.service;

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

    public PermissionResponse create(PermissionRequest request) {
        Permission permission = permissionMapper.toPermission(request);
        permission = permissionRepository.save(permission);
        return permissionMapper.toPermissionResponse(permission);
    }

    public List<PermissionResponse> getAll() {
        return permissionRepository.findAll()
                .stream()
                .map(permissionMapper::toPermissionResponse)
                .toList();
    }

    public void deleteById(String permissionId) {
        permissionRepository.deleteById(permissionId);
    }
}
