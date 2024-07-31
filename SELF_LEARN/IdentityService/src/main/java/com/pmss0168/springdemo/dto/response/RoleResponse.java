package com.pmss0168.springdemo.dto.response;

import com.pmss0168.springdemo.entity.Permission;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Set;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class RoleResponse {
    private String name;
    private String description;
    private Set<Permission> permissions;
}
