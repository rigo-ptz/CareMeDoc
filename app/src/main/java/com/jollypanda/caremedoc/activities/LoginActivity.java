package com.jollypanda.caremedoc.activities;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.jollypanda.caremedoc.R;
import com.jollypanda.caremedoc.tools.Account;
import com.jollypanda.caremedoc.tools.Constants;

import butterknife.Bind;
import butterknife.ButterKnife;
import butterknife.OnClick;

/**
 * Class for login process. Now it's just a stub,
 * because of this feature not supported in SIB.
 *
 * @author Yamushev Igor
 * @since 18.04.2016
 */
public class LoginActivity extends BaseAppCompatActivity {

    @Bind(R.id.etLogin)
    EditText etLogin;

    @Bind(R.id.etPassword)
    EditText etPassword;

    @Bind(R.id.btnEnter)
    Button btnEnter;

    @Bind(R.id.rlProgress)
    RelativeLayout rlProgress;

    private String mLogin;
    private String mPassword;

    private Handler mHandler;
    private Handler.Callback hc = new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    rlProgress.setVisibility(View.GONE);
                    gotoMainActivity();
                    return true;
                case 2:
                    rlProgress.setVisibility(View.GONE);
                    Toast.makeText(LoginActivity.this, getString(R.string.signInFail), Toast.LENGTH_LONG).show();
                    return true;
                default:
                    break;
            }
            return false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        ButterKnife.bind(this);

        setTextWatchers();
        mHandler = new Handler(hc);
    }

    private void setTextWatchers() {
        TextWatcher tvValidattor = new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable s) {
                validateLoginAndPass();
            }
        };
        etLogin.addTextChangedListener(tvValidattor);
        etPassword.addTextChangedListener(tvValidattor);
    }

    private void validateLoginAndPass() {
        if (!etLogin.getText().toString().equals("")
                && !etPassword.getText().toString().equals(""))
            btnEnter.setEnabled(true);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        ButterKnife.unbind(this);
    }

    @OnClick(R.id.btnEnter)
    public void onEnterClicked() {
        rlProgress.setVisibility(View.VISIBLE);
        if (sharedPrefsContainLogPassAndToken()) {
            stubLogin(etLogin.getText().toString(), etPassword.getText().toString());
        } else {
            Account.getInstance().saveLogin(getSharedPreferences(Constants.SHARED_PREFS, 0), etLogin.getText().toString());
            Account.getInstance().savePassword(getSharedPreferences(Constants.SHARED_PREFS, 0), etPassword.getText().toString());
            stubLogin(null, null);
        }
    }

    private void stubLogin(String login, String password) {
        final boolean successSignIn;
        if (login != null && password != null) {
            SharedPreferences sp = getSharedPreferences(Constants.SHARED_PREFS, 0);
            if (login.equals(sp.getString(Constants.SHARED_PREFS_LOGIN, "")) &&
                    password.equals(sp.getString(Constants.SHARED_PREFS_PASS, "")))
                successSignIn = true;
            else
                successSignIn = false;
        } else {
            successSignIn = true;
        }
        // FIXME: 21.04.2016 it just stub, because we have no implementation of login on server
        Thread stubThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (successSignIn)
                    mHandler.sendEmptyMessage(1);
                else
                    mHandler.sendEmptyMessage(2);
            }
        });
        stubThread.start();
    }

    private boolean sharedPrefsContainLogPassAndToken() {
        SharedPreferences sp = getSharedPreferences(Constants.SHARED_PREFS, 0);
        if (sp.contains(Constants.SHARED_PREFS_PASS) &&
                sp.contains(Constants.SHARED_PREFS_LOGIN))
            return true;
        else
            return false;
    }

    private void gotoMainActivity() {
        Intent i = new Intent(this, MainActivity.class);
        startActivity(i);
    }
}
