package com.pmss0168.springdemo.validator;

import jakarta.validation.ConstraintValidator;
import jakarta.validation.ConstraintValidatorContext;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Objects;

public class BirthDayValidator implements ConstraintValidator<BirthDayConstraint, LocalDate> {
    private int min;

    @Override
    public void initialize(BirthDayConstraint constraintAnnotation) {
        ConstraintValidator.super.initialize(constraintAnnotation);
        min = constraintAnnotation.min();
    }

    @Override
    public boolean isValid(LocalDate value, ConstraintValidatorContext constraintValidatorContext) {
        return Objects.isNull(value) || ChronoUnit.YEARS.between(value, LocalDate.now()) >= min;
    }
}
