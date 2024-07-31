package com.pmss0168.springdemo.mapper;

import com.pmss0168.springdemo.dto.request.PermissionRequest;
import com.pmss0168.springdemo.dto.response.PermissionResponse;
import com.pmss0168.springdemo.entity.Permission;
import org.mapstruct.Mapper;
import org.mapstruct.MappingTarget;

@Mapper(componentModel = "spring")
public interface PermissionMapper {
    Permission toPermission(PermissionRequest request);
    PermissionResponse toPermissionResponse(Permission permission);
    void updatePermission(@MappingTarget Permission permission, PermissionRequest request);
}
