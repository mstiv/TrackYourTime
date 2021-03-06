/*
 * TrackYourTime - cross-platform time tracker
 * Copyright (C) 2015-2017  Alexander Basov <basovav@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include "../data/cdatamanager.h"
#include "notification_dummy.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT
protected:
    cDataManager*       m_DataManager;
    QPoint              m_NotifPos;
    QPoint              m_NotifSize;
    notification_dummy* m_NotificationSetupWindow;
    void loadPreferences();
    void applyPreferences();
    QString getDefaultMessage();
public:
    explicit SettingsWindow(cDataManager* DataManager);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
protected:
    virtual void showEvent(QShowEvent * event) override;
signals:
    void preferencesChange();
public slots:
    void handleButtonApply();
    void handleButtonCancel();
    void handleButtonBrowse();
    void handleButtonBrowseBackup();

    void handleButtonSetNotificationWindow();
    void handleButtonResetNotificationWindow();
    void handleButtonSetDefaultMessage();

    void onNotificationSetPosAndSize();
private slots:
    void on_comboBoxMouseBehavior_currentIndexChanged(int index);
    void on_comboBoxCategorySelectionBehavior_currentIndexChanged(int index);
    void on_checkBoxHideWIndowBorders_clicked();
    void on_pushButton_clicked();
};

#endif // SETTINGSWINDOW_H
