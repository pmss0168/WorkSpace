package com.pmss0168.springdemo.validator;

import com.nimbusds.jose.Payload;
import jakarta.validation.Constraint;
import org.springframework.stereotype.Component;

import java.lang.annotation.*;

@Target({ElementType.FIELD})     //Object target
@Retention(RetentionPolicy.RUNTIME)     //When this annotation excuse
@Constraint(validatedBy = {BirthDayValidator.class})
public @interface BirthDayConstraint {
    String message() default "Invalid Birthday";
    Class<?>[] groups() default { };
    Class<? extends Payload>[] payload() default { };

    //Customize method
    int min() default 18;
}
