package com.pmss0168.springdemo.controller;

import com.pmss0168.springdemo.dto.request.APIResponse;
import com.pmss0168.springdemo.dto.request.PermissionRequest;
import com.pmss0168.springdemo.dto.request.RoleRequest;
import com.pmss0168.springdemo.dto.response.PermissionResponse;
import com.pmss0168.springdemo.dto.response.RoleResponse;
import com.pmss0168.springdemo.service.RoleService;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/roles")
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class RoleController {
    RoleService roleService;

    @PostMapping
    public APIResponse<RoleResponse> createRole(@RequestBody RoleRequest request) {
        return APIResponse.<RoleResponse>builder()
                .result(roleService.create(request))
                .build();
    }

    @GetMapping
    public APIResponse<List<RoleResponse>> getAllRoles() {
        return APIResponse.<List<RoleResponse>>builder()
                .result(roleService.getAll())
                .build();
    }

    @DeleteMapping("/{roleId}")
    public APIResponse<Void> deleteRole(@PathVariable String roleId) {
        roleService.deleteById(roleId);
        return APIResponse.<Void>builder().build();
    }
}
