package com.pmss0168.springdemo.controller;

import com.pmss0168.springdemo.dto.request.APIResponse;
import com.pmss0168.springdemo.dto.request.PermissionRequest;
import com.pmss0168.springdemo.dto.response.PermissionResponse;
import com.pmss0168.springdemo.service.PermissionService;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/permissions")
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class PermissionController {
    PermissionService permissionService;

    @PostMapping
    public APIResponse<PermissionResponse> createPermission(@RequestBody PermissionRequest request) {
        return APIResponse.<PermissionResponse>builder()
                .result(permissionService.create(request))
                .build();
    }

    @GetMapping
    public APIResponse<List<PermissionResponse>> getAllPermissions() {
        return APIResponse.<List<PermissionResponse>>builder()
                .result(permissionService.getAll())
                .build();
    }

    @DeleteMapping("/{permissionId}")
    public APIResponse<Void> deletePermission(@PathVariable String permissionId) {
        permissionService.deleteById(permissionId);
        return APIResponse.<Void>builder().build();
    }
}
