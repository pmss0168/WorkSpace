package com.pmss0168.springdemo.controller;

import com.nimbusds.jose.JOSEException;
import com.pmss0168.springdemo.dto.request.APIResponse;
import com.pmss0168.springdemo.dto.request.AuthenticationRequest;
import com.pmss0168.springdemo.dto.request.IntrospectRequest;
import com.pmss0168.springdemo.dto.response.AuthenticationResponse;
import com.pmss0168.springdemo.dto.response.IntrospectResponse;
import com.pmss0168.springdemo.service.AuthenticationService;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.experimental.FieldDefaults;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.text.ParseException;

@RestController
@RequestMapping("/auth")
@RequiredArgsConstructor
@FieldDefaults(level = AccessLevel.PRIVATE, makeFinal = true)
public class AuthenticationController {
    AuthenticationService authenticationService;

    @PostMapping("/token")
    public APIResponse<AuthenticationResponse> login(@RequestBody AuthenticationRequest request) {
        var result = authenticationService.authenticate(request);
        return APIResponse.<AuthenticationResponse>builder()
                .result(result)
                .build();
    }
    @PostMapping("/introspect")
    public APIResponse<IntrospectResponse> introspect(@RequestBody IntrospectRequest request){
        var result = authenticationService.introspect(request);
        return APIResponse.<IntrospectResponse>builder()
                .result(result)
                .build();
    }
}
