# 📬 Gmail API for Drupal 7

使用 Gmail API 完整取代 Drupal 7 全站的寄信功能，支援 HTML 郵件、自動 Refresh Token、後台授權與測試。

## 功能特色

- ✅ 使用 Gmail API 寄送 Email（不再使用 `mail()` 或 SMTP）
- ✅ 支援 HTML 郵件內容
- ✅ Access Token 儲存於 Drupal 系統設定（`variable`）
- ✅ 自動 refresh token，不需重新授權
- ✅ 可取代 Drupal 全站寄信（註冊、聯絡表單等）
- ✅ 提供後台測試寄信功能
- ✅ 中文主旨正確編碼（無亂碼）

## 安裝方式

1. 將此模組放入 `sites/all/modules/gmail_api/`
2. 使用 Composer 安裝 Gmail API PHP 套件：

```bash
composer require google/apiclient:^1.1

