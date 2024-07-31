package com.pmss0168.springdemo.dto.request;

import com.pmss0168.springdemo.enums.ErrorCode;
import com.pmss0168.springdemo.validator.BirthDayConstraint;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class UserCreationRequest {
    @Size(min = 8, max = 36, message = "USERNAME_INVALID")
    private String username;
    @Size(min = 8, max = 36, message = "PASSWORD_INVALID")
    private String password;
    private String firstName;
    private String lastName;
    @BirthDayConstraint(message = "BIRTHDAY_INVALID")
    private LocalDate birthDate;
}
