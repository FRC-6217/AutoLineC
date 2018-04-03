/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                              */
/*---------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <memory>
#include <string>


void Robot::RobotInit() {
	m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
	m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	m_timer.Start();
	_victorL1 = new frc::VictorSP(6);
	_victorL2 = new frc::VictorSP(7);
	_victorR1 = new frc::VictorSP(8);
	_victorR2 = new frc::VictorSP(9);

	// Speed Controller Groups
	_leftSide = new SpeedControllerGroup(*_victorL1, *_victorL2);
	_rightSide = new SpeedControllerGroup(*_victorR1, *_victorR2);

	// Differential Drive Class
	_driveTrain = new DifferentialDrive(*_leftSide, *_rightSide);
}

void Robot::AutonomousInit() {
	m_timer.Reset();
	m_timer.Start();
}

void Robot::AutonomousPeriodic() {
	if (m_timer.Get() < 7.0){
		_driveTrain->ArcadeDrive(.6, 0, true);
	}
	else{
		_driveTrain->ArcadeDrive(0, 0, true);
	}
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
