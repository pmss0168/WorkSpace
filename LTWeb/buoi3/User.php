<?php
class User{
	private  $fullname;
    private  $email;
    private  $birthday;
    private  $gender;
    public function User(){

    }
	public function getFullname() {
		return $this->fullname;
	}
	public function setFullname( $fullname) {
		$this->fullname = $fullname;
	}
	public function getEmail() {
		return $this->email;
	}
	public function setEmail( $email) {
		$this->email = $email;
	}
	public function getBirthday() {
		return $this->birthday;
	}
	public function setBirthday( $birthday) {
		$this->birthday = $birthday;
	}
	public function getGender() {
		return $this->gender;
	}
	public function setGender( $gender) {
		$this->gender = $gender;
	}
    
}
?>