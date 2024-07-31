package com.pmss0168.springdemo.mapper;

import com.pmss0168.springdemo.dto.request.RoleRequest;
import com.pmss0168.springdemo.dto.response.RoleResponse;
import com.pmss0168.springdemo.entity.Role;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.MappingTarget;

@Mapper(componentModel = "spring")
public interface RoleMapper {
    @Mapping(target = "permissions", ignore = true)
    Role toRole(RoleRequest request);
    RoleResponse toRoleResponse(Role role);
    @Mapping(target = "permissions", ignore = true)
    void updateRole(@MappingTarget Role role, RoleRequest request);
}
