#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "urlrequestinterceptor.h"
#include <QAction>
#include <QByteArray>
#include <QCommandLineParser>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QShortcut>
#include <QWebEngineFullScreenRequest>
#include <QWebEngineView>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  void set_provider(QString);
  void set_useragent(QString);
  ~MainWindow();
  // QAction amazon();

private slots:
  // slots for handlers of hotkeys
  void slotShortcutF11();
  void slotShortcutCtrlQ();
  void ShowContextMenu(const QPoint &pos);

protected:
  // save window geometry
  void closeEvent(QCloseEvent *);

private:
  Ui::MainWindow *ui;
  QWebEngineView *webview;
  QShortcut *keyF11;   // Entity of F11 hotkey
  QShortcut *keyCtrlQ; // Entity of Ctrl + D hotkeys
  QSettings *appSettings;
  QSettings *provSettings;
  void fullScreenRequested(QWebEngineFullScreenRequest request);
  void writeSettings();
  void readSettings();
  void restore();

  UrlRequestInterceptor *m_interceptor;
};

#endif // MAINWINDOW_H
