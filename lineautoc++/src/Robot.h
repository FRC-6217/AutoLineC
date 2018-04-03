/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <Timer.h>
#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include <wpilib.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
	frc::Timer m_timer;
	frc::VictorSP* _victorL1;
	frc::VictorSP* _victorL2;
	frc::VictorSP* _victorR1;
	frc::VictorSP* _victorR2;

	// Speed Controller Groups
	SpeedControllerGroup * _leftSide;
	SpeedControllerGroup * _rightSide;

	// Differential Drive Class
	DifferentialDrive * _driveTrain;
};
