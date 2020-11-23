// This file is part of OpenMVG, an Open Multiple View Geometry C++ library.

// Copyright (c) 2015 Pierre MOULON.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <QApplication>
#include "MainWindow.hpp"
using namespace std;

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  QCoreApplication::setApplicationName("OpenMVG GCR tool");
  QCoreApplication::setApplicationVersion("1.0");

  QCommandLineParser parser;
  parser.setApplicationDescription("GCR tool");
  parser.addHelpOption();
  parser.addVersionOption();

  QCommandLineOption bundleAdjustmentOption("b", QCoreApplication::translate("main", "Perform bundle adjustment"));
  parser.addOption(bundleAdjustmentOption);

  // Process the actual command line arguments given by the user
  parser.process(app);

  bool doBundleAdjustment = parser.isSet(bundleAdjustmentOption);

  cout << "doBundleAdjustment = " << doBundleAdjustment << endl;

  MainWindow * mainWindow = new MainWindow;
  mainWindow->SetDoBundleAdjustment(doBundleAdjustment);
  mainWindow->show();

  return app.exec();
}
